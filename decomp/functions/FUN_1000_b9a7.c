/* 1000:b9a7 */

undefined4 __cdecl16near FUN_1000_b9a7(void)

{
  uint uVar1;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar2;
  undefined2 in_DX;
  undefined2 in_BX;
  uint uVar3;
  uint *unaff_SI;
  uint *puVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  bVar5 = false;
  FUN_1000_b4d8();
  if (bVar5) {
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_a61d(in_BX,in_CX);
  puVar4 = (uint *)0x0;
  uVar3 = 0x1f1;
  iVar2 = 0x900;
  do {
    uVar1 = *puVar4;
    if (uVar1 < uVar3) {
      bVar5 = false;
      if (((char)puVar4[-0x16c1] == '\0') ||
         (bVar5 = true, (byte)((char)puVar4[-0x16c1] - 0xcU) < 4)) {
        FUN_1000_ae9e();
        if (!bVar5) {
          uVar3 = uVar1;
          unaff_SI = puVar4;
        }
      }
    }
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(CONCAT11((char)(((uint)unaff_SI >> 1) / 0x30),(char)(((uint)unaff_SI >> 1) % 0x30)
                          ),uVar3);
}


