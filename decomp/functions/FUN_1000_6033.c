/* 1000:6033 */

undefined4 __cdecl16near FUN_1000_6033(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 in_AX;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  undefined2 in_DX;
  undefined2 *puVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar10;
  undefined1 uVar11;
  
  uVar10 = *(int *)0x3bc2 != -1;
  uVar11 = *(int *)0x3bc2 == -1;
  if ((bool)uVar11) {
LAB_1000_60dc:
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_6c3f();
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_662c();
  FUN_1000_c492();
  FUN_1000_c449();
  do {
    FUN_1000_687e();
    if (!(bool)uVar10) {
      FUN_1000_6f4b();
      FUN_1000_68a0();
      if (!(bool)uVar10) {
        *(undefined2 *)0x3bc4 = *(undefined2 *)0xdb7e;
        uVar4 = *(uint *)0x3bc2;
        if (0x33 < uVar4) {
          uVar4 = uVar4 - 100;
        }
        puVar7 = (undefined2 *)((undefined *)&DAT_0000_fa3e + uVar4 * 0x10);
        puVar9 = (undefined2 *)0x3c08;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          puVar3 = puVar9;
          puVar9 = puVar9 + 1;
          puVar2 = puVar7;
          puVar7 = puVar7 + 1;
          *puVar3 = *puVar2;
        }
        uVar10 = false;
        *(undefined1 *)puVar9 = 0;
        *(undefined2 *)0x3bce = 0;
        FUN_1000_6d3a();
        if ((!(bool)uVar10) && (uVar10 = 0, *(int *)(*(int *)0x3e94 + 0xc) == 0)) {
          *(undefined2 *)0x3bce = 1;
        }
        FUN_1000_60e5();
        if (!(bool)uVar10) {
          puVar8 = (undefined1 *)0xdb7d;
          puVar7 = (undefined2 *)0xe47c;
          iVar6 = 0x900;
          puVar5 = (undefined *)&DAT_0000_6400;
          do {
            puVar1 = puVar8;
            puVar8 = puVar8 + -1;
            puVar5 = (undefined *)CONCAT11((char)((uint)puVar5 >> 8),*puVar1);
            puVar2 = puVar7;
            puVar7 = puVar7 + -1;
            *puVar2 = puVar5;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          *(undefined2 *)0x346e = *(undefined2 *)0x3bc2;
          goto LAB_1000_60dc;
        }
LAB_1000_60df:
        FUN_1000_051b();
        return CONCAT22(in_DX,in_AX);
      }
    }
    FUN_1000_6cb5();
    if (!(bool)uVar11) goto LAB_1000_60df;
  } while( true );
}


