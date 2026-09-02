/* 1000:5917 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015940) overlaps instruction at (ram,0x0001593f)
    */

undefined4 FUN_1000_5917(int param_1,int param_2,undefined1 *param_3,undefined2 param_4)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  byte bVar7;
  char cVar8;
  int iVar9;
  char extraout_DH;
  undefined2 extraout_DX;
  undefined1 *unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  undefined2 in_stack_00000016;
  undefined2 in_stack_0000001a;
  
  bVar10 = false;
                    /* WARNING: Call to offcut address within same function */
  bVar7 = func_0x00015986();
  if (bVar10) {
    (unaff_BP + (int)unaff_SI)[0x2d] = (unaff_BP + (int)unaff_SI)[0x2d] + extraout_DH;
    param_3 = unaff_DI;
  }
  else {
    FUN_1000_5a67();
    cVar8 = in(extraout_DX);
    bVar7 = (cVar8 + 0xb4U | 0xc6) - 0x1b ^ (byte)*(undefined2 *)(unaff_SI + param_2);
  }
  bVar7 = bVar7 + 0x1c;
  if ((char)bVar7 < '\0') {
    bVar10 = false;
                    /* WARNING: Call to offcut address within same function */
    bVar7 = func_0x00015974();
    if (bVar10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_BP = unaff_BP + 1;
    *unaff_SI = *unaff_SI & bVar7;
  }
  pbVar2 = param_3 + -0x10;
  bVar3 = *pbVar2;
  *pbVar2 = *pbVar2 + bVar7;
  *unaff_SI = *unaff_SI + bVar7 + CARRY1(bVar3,bVar7);
  uVar6 = FUN_1000_5ab6();
  *param_3 = uVar6;
  puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
  pcVar1 = puVar5 + param_1;
  *pcVar1 = *pcVar1 + (char)((uint)param_4 >> 8);
  puVar4 = unaff_BP + 1;
  *unaff_BP = *puVar5;
  *puVar4 = 0x20;
  for (iVar9 = 10; puVar4 = puVar4 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar4 = 0;
  }
  return CONCAT22(in_stack_00000016,in_stack_0000001a);
}


