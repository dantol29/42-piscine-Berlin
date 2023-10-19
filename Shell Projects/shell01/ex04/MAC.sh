ifconfig | grep ether | sed "s/ether //" |  tr -d ' ' | cut -b 1-17
