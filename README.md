# APVAS+
A protocol that reduces the memory consumption of routers running BGPsec by using aggregate signatures when validating AS_PATHs in routing information.

# usage
The APVAS+ prototype is based on the BIRD Internet Routing Daemon.
The way to handle the daemons, e.g., start, stop, configuration, etc., is unified with the original BIRD.

1. Download and install BIRD ver 1.6.0 according to the following site.

   https://bird.network.cz/

1. Download and install TEPLA BIRD ver 2.0 according to the following site.
  
   http://www.cipher.risk.tsukuba.ac.jp/tepla/index.html

1. Replace bird-1.6.0/proto/bgp/packets.c 
   This is packets.c with an example of the second AS from the route generator AS in the network. 
   In addition, please add bird-1.6.0/proto/bgp/aggsign.h.

1. Run setup.sh

## license

[MIT](https://opensource.org/licenses/mit-license.php)

## Developer

- [takemr](https://github.com/takemr)
- [Naoto Yanai](https://github.com/naotoyanai)
