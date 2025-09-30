#!/bin/bash

cp site/vars.h site/vars.h.bak

file="site/vars.h"

counter=0

sed -i 's/\[\]//' ${file}
sed -i 's/char/const char*/' ${file}
cat ${file} | while read line; do
  counter=$((counter + 1))
  varName=$(awk 'NR == '"${counter}"' && NF>1{print $NF}' ${file})
  varName=$(sed 's/;//' <<<${varName})
  sed -i "${counter}s/${varName}/get${varName}(int x) { return ${varName}; }/" ${file}
  sed -i "${counter}s/^/EMSCRIPTEN_KEEPALIVE /" ${file}
done

sed -i '1s/^/#include <emscripten.h>\n/' ${file}
