/* 1000:6994 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_6994(undefined2 param_1,undefined2 param_2,undefined1 *param_3)

{
  byte *pbVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint in_AX;
  char in_CL;
  undefined2 extraout_DX;
  int in_BX;
  int iVar8;
  int unaff_BP;
  uint uVar9;
  uint unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar10;
  
  iVar7 = (in_AX & 0x7f) * 4;
                    /* WARNING: Call to offcut address within same function */
  func_0x000169c4();
  puVar3 = (uint *)(iVar7 + 0x3c22);
  cVar10 = 0xfaff < unaff_DI;
  FUN_1000_71c4();
  *(char *)(in_BX + (int)puVar3) = *(char *)(in_BX + (int)puVar3) + in_CL + cVar10;
  iVar8 = CONCAT11((char)((uint)in_BX >> 8) + (char)in_BX,(char)in_BX);
  FUN_1000_79c3();
  pbVar1 = (byte *)((int)puVar3 + iVar8 + 0x5e);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + (byte)iVar8;
  *(uint *)(param_3 + unaff_BP + -0xc) =
       (*(int *)(param_3 + unaff_BP + -0xc) - (int)param_3) - (uint)CARRY1(bVar2,(byte)iVar8);
  cVar10 = (char)((uint)extraout_DX >> 8) + *(char *)((int)puVar3 + iVar8 + 0x1c10);
  if (-1 < cVar10) {
    uVar5 = *(uint *)(iVar7 + 0x3c62);
    uVar6 = *(uint *)(iVar7 + 0x3c42);
    uVar4 = *puVar3;
    uVar9 = ~(uVar4 & uVar6 & uVar5 & CONCAT11(cVar10,(char)extraout_DX));
    out(0x7e,(char)uVar4);
    out(0x7e,(char)uVar6);
    out(0x7e,(char)uVar5);
    out(0x7e,(char)extraout_DX);
    *param_3 = (char)uVar9;
    out(0x7e,(char)(uVar4 >> 8));
    out(0x7e,(char)(uVar6 >> 8));
    out(0x7e,(char)(uVar5 >> 8));
    out(0x7e,cVar10);
    param_3[1] = (char)(uVar9 >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


