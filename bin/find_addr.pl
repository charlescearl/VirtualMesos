#!/usr/bin/perl -w

use strict;
use XML::XPath;
use XML::XPath::XMLParser;
use Sys::Virt;

# Open libvirt connection and get the domain.
my $conn = Sys::Virt->new (readonly => 1);
my $dom = $conn->get_domain_by_name ($ARGV[0]);

# Get the libvirt XML for the domain.
my $xml = $dom->get_xml_description ();
# print "$xml\n";

# Parse out the MAC addresses using an XPath expression.
my $xp = XML::XPath->new (xml => $xml);
#my $nodes = $xp->find ("//devices/interface[\@type='bridge' and /source/\@bridge='virbr0']");
#my $nodes = $xp->find ("//devices/interface[/source/\@bridge='virbr0']");
my $nodes = $xp->find ("//devices/interface[\@type='bridge']/mac[../source/\@bridge='virbr0']/\@address");
my $node;
my @mac_addrs;
my $node_value;
my $node_subset;
foreach $node ($nodes->get_nodelist) {
    $node_value= ($node->getData);
#    print "$node_value\n";
    push @mac_addrs, lc $node_value;
#    $xp = XML::XPath->new( context => $node );
#    $node_subset= $xp->find ("//mac/\@address");
#    foreach $node_value ($node_subset->get_nodelist){
#	print "$node_value\n";
#	
#}
}

# Look up the MAC addresses in the output of 'arp -an'.
my @arp_lines = split /\n/, `/usr/sbin/arp -an`;
foreach (@arp_lines) {
    if (/\((.*?)\) at (.*?) /) {
        my $this_addr = lc $2;
        if (list_member ($this_addr, @mac_addrs)) {
            print "$1\n";
        }
    }
}

sub list_member
{
    local $_;
    my $item = shift;
    foreach (@_) {
        return 1 if $item eq $_;
    }
    return 0;
}
