#include "utils.h"

String util_vecToString(Vec3* vec, String* labelArr){
  String str = "";

  int16_t x = vec->getX();
  int16_t y = vec->getY();
  int16_t z = vec->getZ();

  int16_t vecArr[3] = {x, y, z};
  for(int i = 0; i < 3; i++){
    str += labelArr[i] + ": " + vecArr[i] + " ";
  }

  return str;
}