/* 1000:a83d */

undefined2 __cdecl16near FUN_1000_a83d(void)

{
  undefined2 in_AX;
  uint uVar1;
  byte bVar2;
  char extraout_DL;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  bVar2 = 0;
  uVar1 = FUN_1000_b4a8();
  bVar2 = (((uint)bVar2 << 7 | uVar1 & 0xff00) & 0x100) != 0;
  uVar1 = FUN_1000_b4a8();
  bVar2 = (byte)(((uint)bVar2 << 8 | uVar1 >> 8) >> 1);
  if (extraout_DH == '\0') {
    bVar2 = bVar2 & 0x7c;
  }
  if (extraout_DH == '/') {
    bVar2 = bVar2 & 199;
  }
  if (extraout_DL == '\0') {
    bVar2 = bVar2 & 0xf1;
  }
  if (extraout_DL == '/') {
    bVar2 = bVar2 & 0x1f;
  }
  ((undefined *)&DAT_0000_d27e)[in_BX] = ((undefined *)&DAT_0000_2321)[bVar2];
  return in_AX;
}


