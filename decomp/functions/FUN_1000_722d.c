/* 1000:722d */

undefined2 FUN_1000_722d(void)

{
  undefined1 uVar1;
  char in_AH;
  byte bVar2;
  undefined2 in_DX;
  
  uVar1 = in(in_DX);
  bVar2 = in_AH + 0x81;
  if (0x9f < bVar2) {
    bVar2 = in_AH - 0x3f;
  }
  return CONCAT11(bVar2,uVar1);
}


