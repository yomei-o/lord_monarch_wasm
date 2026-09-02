/* 1000:3ec7 */

undefined4 __cdecl16near FUN_1000_3ec7(void)

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined2 in_AX;
  undefined2 in_DX;
  uint uVar5;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar6;
  
  if ((((undefined *)&DAT_0000_d27e)[unaff_DI] == '\0') ||
     ((byte)(((undefined *)&DAT_0000_d27e)[unaff_DI] - 0xc) < 4)) {
    bVar3 = FUN_1000_a61d();
    bVar6 = 0xf7 < bVar3;
    uVar4 = FUN_1000_ae9e();
    if (!bVar6) {
      bVar6 = false;
      FUN_1000_abc7();
      if (!bVar6) {
        uVar5 = *(uint *)(unaff_SI + 6);
        if (200 < uVar5) {
          uVar5 = 200;
        }
        *(uint *)((undefined *)&DAT_0000_d27e + *(int *)(unaff_SI + 4)) =
             CONCAT11(((byte)uVar5 >> 1) + 1,uVar4);
        puVar1 = (uint *)(unaff_SI + 6);
        uVar2 = *puVar1;
        *puVar1 = *puVar1 - uVar5;
        if (uVar2 < uVar5 || *puVar1 == 0) {
          FUN_1000_a9ca();
        }
        return CONCAT22(in_DX,in_AX);
      }
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}


