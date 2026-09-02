/* 1000:ba12 */

undefined4 __cdecl16near FUN_1000_ba12(void)

{
  undefined2 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint *unaff_SI;
  uint *puVar5;
  undefined2 unaff_DS;
  
  uVar1 = FUN_1000_a61d();
  puVar5 = (uint *)0x0;
  uVar4 = 0x1f1;
  iVar2 = 0x900;
  do {
    if ((((*puVar5 < uVar4) && (bVar3 = (char)puVar5[-0x16c1] - 8, bVar3 < 4)) &&
        (bVar3 != (byte)uVar1)) && (bVar3 != (byte)((uint)uVar1 >> 8))) {
      uVar4 = *puVar5;
      unaff_SI = puVar5;
    }
    puVar5 = puVar5 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(CONCAT11((char)(((uint)unaff_SI >> 1) / 0x30),(char)(((uint)unaff_SI >> 1) % 0x30)
                          ),uVar4);
}


