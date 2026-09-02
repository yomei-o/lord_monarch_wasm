/* 1000:56d7 */

int FUN_1000_56d7(byte *param_1)

{
  uint *puVar1;
  byte *pbVar2;
  byte extraout_AL;
  byte bVar3;
  byte extraout_AH;
  uint uVar4;
  int iVar5;
  byte extraout_AH_00;
  byte extraout_AH_01;
  byte extraout_DL;
  byte bVar6;
  char extraout_DH;
  char cVar7;
  int in_BX;
  int iVar8;
  int unaff_BP;
  byte *unaff_SI;
  code *unaff_DI;
  byte *pbVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_GS;
  undefined1 in_CF;
  undefined1 uVar10;
  bool bVar11;
  char in_SF;
  char in_OF;
  undefined4 uVar12;
  code *in_stack_00000000;
  
  iVar5 = in_BX;
  do {
    iVar8 = iVar5;
    FUN_1000_5712();
    if ((bool)in_CF) {
      if (in_BX != 1) {
LAB_1000_570c:
        uVar12 = FUN_1000_5782();
        if ((int)uVar12 == *(int *)0x3e98) {
          out(*(undefined2 *)unaff_SI,(int)((ulong)uVar12 >> 0x10));
        }
LAB_1000_571b:
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar5 = (*unaff_DI)();
        return iVar5;
      }
      uVar10 = true;
      in_stack_00000000 = unaff_DI;
      if (in_OF == in_SF) goto code_r0x0001570a;
      unaff_SI[iVar8] = unaff_SI[iVar8] | extraout_AL;
      iVar5 = 0;
      bVar6 = extraout_DL;
      cVar7 = extraout_DH;
      bVar3 = extraout_AL;
      goto LAB_1000_574a;
    }
    uVar4 = CONCAT11(extraout_AH,0xe);
    unaff_BP = unaff_BP + *(int *)(unaff_SI + iVar8 + 9);
    *(int *)(unaff_SI + iVar8) = *(int *)(unaff_SI + iVar8) + unaff_BP;
    puVar1 = (uint *)(unaff_SI + iVar8);
    in_CF = uVar4 < *puVar1;
    in_OF = SBORROW2(uVar4,*puVar1);
    in_SF = (int)(uVar4 - *puVar1) < 0;
    if (!(bool)in_CF) {
      uVar10 = 0;
      unaff_SI[iVar8 + -0x3ccc] = unaff_SI[iVar8 + -0x3ccc] ^ (byte)(uVar4 - *puVar1);
      (*(code *)*(undefined2 *)&DAT_0000_3e7c)();
      unaff_SI = param_1;
code_r0x0001570a:
      unaff_DI = in_stack_00000000;
      if ((bool)uVar10) goto LAB_1000_571b;
      goto LAB_1000_570c;
    }
    bVar11 = iVar5 != 1;
    iVar5 = iVar8;
  } while (bVar11);
  bVar3 = 0xff;
  iVar5 = 0;
  goto LAB_1000_5771;
LAB_1000_574a:
  if (bVar3 != extraout_AH) goto code_r0x0001574e;
  goto LAB_1000_5754;
code_r0x0001574e:
  bVar3 = bVar3 << 1 | (char)bVar3 < '\0';
  iVar5 = iVar5 + -1;
  if (iVar5 != 0) goto LAB_1000_574a;
  bVar6 = bVar6 - 1;
LAB_1000_5754:
  bVar6 = bVar6 + 1;
  cVar7 = cVar7 + -1;
  if (cVar7 != '\0') {
    pbVar2 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    bVar3 = *pbVar2;
    iVar5 = 8;
    goto LAB_1000_574a;
  }
  bVar11 = bVar6 < 2;
  if (bVar11) {
LAB_1000_577c:
    iVar8 = 0;
    do {
      pbVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      iVar8 = iVar8 + (uint)*pbVar2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return iVar8;
  }
  unaff_SI = unaff_SI + 1;
  FUN_1000_578e();
  bVar3 = extraout_AH_00;
  if (bVar11) {
    bVar11 = true;
    FUN_1000_578e();
    bVar3 = extraout_AH_01;
    if (bVar11) goto LAB_1000_577c;
  }
  iVar5 = 0x40;
LAB_1000_5771:
  pbVar9 = unaff_SI;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pbVar2 = pbVar9;
    pbVar9 = pbVar9 + 1;
  } while (bVar3 == *pbVar2);
  *unaff_SI = *unaff_SI ^ bVar3;
  return CONCAT11(bVar3,bVar3);
}


