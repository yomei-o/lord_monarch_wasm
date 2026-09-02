/* 1000:71f7 */

undefined2 FUN_1000_71f7(void)

{
  byte in_AL;
  byte bVar1;
  char in_AH;
  byte bVar2;
  char cVar3;
  
  bVar2 = in_AH + 0x8f;
  if (0x2e < bVar2) {
    bVar2 = in_AH + 0x4f;
  }
  cVar3 = bVar2 * '\x02' + '\x01';
  if (0x7f < in_AL) {
    in_AL = in_AL - 1;
  }
  bVar1 = in_AL - 0x1f;
  if (0x7e < bVar1) {
    bVar1 = in_AL + 0x83;
    cVar3 = bVar2 * '\x02' + '\x02';
  }
  return CONCAT11(cVar3,bVar1);
}


