/* 1000:a9ca */

undefined2 __cdecl16near FUN_1000_a9ca(void)

{
  byte bVar1;
  uint *puVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar5;
  undefined1 *unaff_SI;
  byte *pbVar6;
  undefined2 unaff_DS;
  
  *(undefined2 *)(unaff_SI + 6) = 0;
  unaff_SI[0xb] = 0xff;
  if ((unaff_SI[10] & 0x20) != 0) {
    unaff_SI[0xe] = 3;
    bVar1 = unaff_SI[0xc];
    *(undefined2 *)0xc546 = *(undefined2 *)((undefined *)&DAT_0000_12ad + (uint)bVar1 * 2);
    puVar2 = *(uint **)((undefined *)&DAT_0000_12ef + (uint)bVar1 * 2);
    *puVar2 = *puVar2 | 1;
    *(undefined1 *)((int)puVar2 + 0x15) = unaff_SI[0xf];
    puVar2[3] = 0;
    uVar3 = *(undefined2 *)&DAT_0000_3be2;
    uVar4 = *(undefined2 *)&DAT_0000_3be4;
    *(undefined2 *)&DAT_0000_3be4 = *(undefined2 *)(unaff_SI + 2);
    FUN_1000_a656();
    bVar1 = unaff_SI[0xc];
    pbVar6 = (byte *)&DAT_0000_c800;
    iVar5 = 0x40;
    do {
      if (((*pbVar6 & 0x80) == 0) && (bVar1 == pbVar6[0xc])) {
        pbVar6[10] = pbVar6[10] & 0x20 | 0xc;
        pbVar6[1] = 6;
        *pbVar6 = *pbVar6 | 1;
        pbVar6[0xb] = 0xff;
      }
      pbVar6 = pbVar6 + 0x10;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_1000_0d12(CONCAT11(0x80,bVar1),in_CX);
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
    FUN_1000_c921();
    *(undefined2 *)((undefined *)&DAT_0000_e47e + *(int *)(unaff_SI + 4)) = 0;
    FUN_1000_b102();
    *(undefined2 *)&DAT_0000_3be4 = uVar4;
    *(undefined2 *)&DAT_0000_3be2 = uVar3;
    FUN_1000_7c9e();
    FUN_1000_72ad();
  }
  *(undefined2 *)((undefined *)&DAT_0000_e47e + *(int *)(unaff_SI + 4)) = 0;
  *unaff_SI = 0x80;
  if (unaff_SI == (undefined1 *)*(undefined2 *)&DAT_0000_32bf) {
    *(undefined2 *)&DAT_0000_32bf = 0;
  }
  return in_AX;
}


