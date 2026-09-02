/* 1000:3dc0 */

/* WARNING: Instruction at (ram,0x00013dc1) overlaps instruction at (ram,0x00013dc0)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_3dc0(undefined2 param_1,undefined2 param_2)

{
  char *pcVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  undefined2 uVar6;
  byte bVar7;
  undefined1 uVar8;
  undefined2 uVar9;
  char cVar11;
  undefined2 in_CX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  char cVar13;
  uint uVar10;
  
  do {
    func_0x00013c6e();
    FUN_1000_6427();
LAB_1000_3d87:
    do {
      uVar9 = func_0x0001ba2a();
      bVar7 = (byte)uVar9 & (byte)((uint)in_BX >> 8);
      uVar10 = CONCAT11((char)((uint)uVar9 >> 8),bVar7);
    } while (bVar7 == 0);
    if ((bVar7 & 0x20) != 0) {
      puVar2 = (uint *)0x82e8;
      uVar4 = *puVar2;
      *puVar2 = *puVar2 + uVar10;
      pbVar3 = (byte *)(in_BX + unaff_SI + -8);
      bVar5 = *pbVar3;
      *pbVar3 = (byte)(CONCAT11(CARRY2(uVar4,uVar10),bVar5) >> 2) | bVar5 << 7;
LAB_1000_3e15:
      return CONCAT11(bVar7,*(undefined1 *)unaff_DI);
    }
    if ((bVar7 & 0x40) != 0) goto LAB_1000_3e15;
    if ((bVar7 & 3) == 0) {
      unaff_DI = (undefined2 *)((int)unaff_DI + uVar10);
      goto LAB_1000_3e15;
    }
    bVar12 = false;
    if (*(char *)0x32e5 != '\0') {
      uVar9 = FUN_1000_3e1b();
      if (!bVar12) {
        uVar6 = *unaff_DI;
        break;
      }
      goto LAB_1000_3d87;
    }
    FUN_1000_3e1b();
    if (bVar12) goto LAB_1000_3d87;
    func_0x0001fe8c();
    if ((char)((uint)param_2 >> 8) == -1) {
      param_2 = 0x3db8;
      uVar8 = FUN_1000_840f();
      *(undefined1 *)unaff_DI = uVar8;
      func_0x000183b3();
      goto LAB_1000_3d87;
    }
    *unaff_DI = param_2;
    param_2 = 0x3dc1;
    FUN_1000_63f1();
    func_0x00013c6e();
  } while( true );
  while( true ) {
    uVar9 = FUN_1000_3e1b();
    cVar11 = (char)((uint)in_CX >> 8);
    if (bVar12) break;
    cVar11 = (char)((uint)uVar9 >> 8);
    if (cVar11 != -1) {
      *(char *)((int)unaff_DI + 1) = cVar11;
    }
    *(char *)unaff_DI = (char)uVar9;
    bVar7 = func_0x0001ba52();
    cVar11 = (char)((uint)in_CX >> 8);
    bVar12 = false;
    if ((bVar7 & 3) == 0) break;
  }
  uVar9 = *unaff_DI;
  *unaff_DI = uVar6;
  bVar7 = (byte)((uint)uVar9 >> 8);
  cVar13 = bVar7 < *(byte *)((int)unaff_DI + 1);
  if (bVar7 == *(byte *)((int)unaff_DI + 1)) {
    func_0x0001780f();
    pcVar1 = (char *)(unaff_BP + unaff_SI + -0x4956);
    *pcVar1 = *pcVar1 + cVar11 + cVar13;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


