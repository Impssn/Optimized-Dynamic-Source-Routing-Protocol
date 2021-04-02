# Optimized-Dynamic-Source-Routing-Protocol
This Algorithm does the Dynamic Source Routing in an Optimized way.
It also has the feature of self-healing of link-breaks by re-directing the packet 
through a proper route that connects the Destination.
  As per the Algorithm we first get the Source and Destination nodes and then find the Least distant node from Source.
  Then we forward the data packet to that node and we find the Least distant node from that node. We keep on doing this
  until we find the Destination node. Once we find the Destination node we pause there and return a Success message.
