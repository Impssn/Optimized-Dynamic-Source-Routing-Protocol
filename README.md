# Optimized-Dynamic-Source-Routing-Protocol
This Algorithm does the _**Dynamic Source Routing in an Optimized way.**_
It also has the feature of _**self-healing**_ _**of link-breaks**_ by re-directing the packet 
through a proper route that connects the Destination.
  As per the Algorithm we first get the Source and Destination nodes and then find the Least distant node from Source.
  Then we forward the data packet to that node and then we find the Least distant node from that node. If we encounter
  any **_link-breaks_** in between then we traverse back to the previous node and forward the packet to the next 
  least distant node than the previous least distant node from that node.We keep on doing this until we find the 
  Destination node. Once we find the Destination node we pause there and return a Success message.
