/* 1000:0bde */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_0bde(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  byte in_AL;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  byte in_CL;
  byte in_CH;
  byte extraout_DL;
  uint extraout_DX;
  int unaff_BP;
  byte *pbVar8;
  byte *unaff_SI;
  int *piVar9;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  byte bVar10;
  undefined1 uVar11;
  char in_stack_00000000;
  undefined2 uStack0004;
  undefined2 in_stack_00000012;
  byte in_stack_00000014;
  undefined2 in_stack_00000016;
  
  do {
    if (in_AL == 0xf6) {
      *unaff_SI = unaff_SI[1];
      unaff_SI = unaff_SI + 4;
    }
    else {
      if (in_AL == 0xff) {
        bVar10 = 9 < ((in_stack_00000000 + 0xfU ^ 0x76) & 0xf) | in_AF;
        uStack0004 = 0xc0e;
        FUN_1000_72b7();
        FUN_1000_72b7();
                    /* WARNING: Call to offcut address within same function */
        func_0x00010cb5();
        FUN_1000_72e3();
        uVar5 = CONCAT11(~extraout_DL,~extraout_DL) & 0x300f;
        bVar3 = (byte)uVar5 | (char)(uVar5 >> 8) * '\x02';
        uVar11 = bVar3 == 0;
        *(byte *)0x32cb = bVar3;
        FUN_1000_0cca();
        *(undefined1 *)0x3b3f = 3;
        FUN_1000_0dd7();
        piVar9 = (int *)0x3b1a;
        iVar6 = FUN_1000_0dd7();
        bVar3 = (byte)(iVar6 / (int)*(char *)(unaff_BP + 0x652a));
        uVar7 = (undefined1)(iVar6 % (int)*(char *)(unaff_BP + 0x652a));
        if (!(bool)uVar11) {
          cVar4 = *(byte *)0x3b42 - *(byte *)0x3b41;
          if (*(byte *)0x3b42 < *(byte *)0x3b41) {
            in_stack_00000012 = 0xc53;
            func_0x00010b3a();
            LOCK();
            bVar10 = *(byte *)0x3b47;
            *(byte *)0x3b47 = 0x80;
            UNLOCK();
            uVar5 = (uint)bVar10;
            if (-1 < (char)bVar10) {
              iVar6 = uVar5 * 4;
              unaff_DI = 0x3afa;
              cVar4 = FUN_1000_0cca();
              *(uint *)(iVar6 + 0x3b1c) = *(uint *)(iVar6 + 0x3b1c) | extraout_DX;
              uVar5 = CONCAT11((char)((uint)(iVar6 + 2) >> 8),(char)(iVar6 + 2) + cVar4 + -1);
            }
            if (*(int *)(uVar5 + 0x35e2) == 0) {
              return;
            }
            *(int *)(unaff_BP + unaff_DI) = *(int *)(unaff_BP + unaff_DI) - (int)&stack0x0016;
            pcVar2 = (char *)(unaff_BP + unaff_DI + -0x7402);
            *pcVar2 = *pcVar2 - in_CL;
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          *(char *)0x3b42 = cVar4;
          piVar9 = (int *)0x103a;
          *(uint *)0xcfe8 = *(uint *)0xcfe8 & CONCAT11(uVar7,cVar4);
          *(int *)(param_1 + unaff_DI) = (int)&stack0x0012 + *(int *)(param_1 + unaff_DI);
          bVar3 = cVar4 + *(char *)(param_1 + 0x103a);
        }
        pbVar1 = (byte *)((int)piVar9 + unaff_BP + 0xaaa);
        *pbVar1 = *pbVar1 ^ in_CH;
        *(int *)0x3f1a = *(int *)0x3f1a + 1;
        *piVar9 = *piVar9 + CONCAT11(uVar7,bVar3 + (9 < (bVar3 & 0xf) | bVar10) * -6 +
                                           (0x99 < bVar3) * -0x60) + (uint)(0x99 < bVar3);
        pcVar2 = (char *)(unaff_BP + unaff_DI + 0x11);
        *pcVar2 = *pcVar2 + in_stack_00000014;
        pbVar1 = (byte *)(unaff_BP + unaff_DI + 0x11);
        uVar7 = CARRY1(*pbVar1,in_stack_00000014);
        *pbVar1 = *pbVar1 + in_stack_00000014;
        in_stack_00000012 = 0xc87;
        FUN_1000_0dcd();
        FUN_1000_0dcd();
        in_stack_00000016 = 0xc93;
        FUN_1000_0dcd();
        *(undefined1 *)0x3b43 = 0;
        bVar10 = (in_CL & 0x1f) % 0x11;
        uVar5 = *(uint *)(unaff_BP + unaff_DI);
        *(uint *)(unaff_BP + unaff_DI) =
             uVar5 << bVar10 | (uint)(CONCAT12(uVar7,uVar5) >> 0x11 - bVar10);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      unaff_SI = unaff_SI + *(byte *)(in_AL + 0x2331);
    }
    while( true ) {
      pbVar8 = unaff_SI;
      unaff_SI = pbVar8 + 1;
      in_AL = *pbVar8;
      if (0xef < in_AL) break;
      if (!CARRY1(in_AL,in_AL)) {
        unaff_SI = pbVar8 + 2;
      }
    }
  } while( true );
}


