/* 1000:c8b0 */

byte __cdecl16near FUN_1000_c8b0(void)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  bool bVar4;
  
  iVar2 = (uint)*(byte *)0x32ce << 8;
  do {
    bVar1 = FUN_1000_c7ce();
    if ((bool)in_ZF) goto LAB_1000_c8c9;
    if (((byte)((uint)iVar2 >> 8) & bVar1) == 0) goto LAB_1000_c8ce;
    in_ZF = *(char *)0x32d0 == '\0';
  } while (!(bool)in_ZF);
  uVar3 = 2;
LAB_1000_c8d0:
  *(undefined1 *)0x32d0 = uVar3;
  return bVar1;
LAB_1000_c8c9:
  do {
    bVar4 = true;
    bVar1 = FUN_1000_c7ce();
  } while (bVar4);
LAB_1000_c8ce:
  uVar3 = 0x14;
  goto LAB_1000_c8d0;
}


