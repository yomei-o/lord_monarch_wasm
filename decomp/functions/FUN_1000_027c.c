/* 1000:027c */

undefined2 __cdecl16near FUN_1000_027c(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined *puVar2;
  undefined2 unaff_DS;
  
  puVar2 = (undefined *)&DAT_0000_c800;
  iVar1 = 0x40;
  do {
    *puVar2 = 0x80;
    puVar2[0xb] = 0xff;
    puVar2 = puVar2 + 0x10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return in_AX;
}


