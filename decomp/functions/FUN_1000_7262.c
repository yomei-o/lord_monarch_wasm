/* 1000:7262 */

uint __cdecl16near FUN_1000_7262(void)

{
  uint in_AX;
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  bVar1 = (byte)((in_AX & 0xff0f) >> 8);
  out(0x7c,(byte)(in_AX & 0xff0f) ^ 0xf | 0x80);
  iVar2 = 4;
  do {
    bVar3 = bVar1 & 1;
    bVar1 = bVar1 >> 1;
    out(0x7e,-bVar3);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}


