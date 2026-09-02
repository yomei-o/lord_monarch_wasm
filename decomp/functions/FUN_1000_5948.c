/* 1000:5948 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_5948(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  byte in_AL;
  int iVar7;
  undefined1 *unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar8;
  bool in_SF;
  undefined2 in_stack_00000016;
  undefined2 in_stack_0000001a;
  
  if (in_SF) {
    bVar8 = false;
                    /* WARNING: Call to offcut address within same function */
    in_AL = func_0x00015974();
    if (bVar8) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_BP = unaff_BP + 1;
    *unaff_SI = *unaff_SI & in_AL;
  }
  pbVar2 = unaff_DI + -0x10;
  bVar3 = *pbVar2;
  *pbVar2 = *pbVar2 + in_AL;
  *unaff_SI = *unaff_SI + in_AL + CARRY1(bVar3,in_AL);
  uVar6 = FUN_1000_5ab6();
  *unaff_DI = uVar6;
  puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
  pcVar1 = puVar5 + param_1;
  *pcVar1 = *pcVar1 + (char)((uint)param_4 >> 8);
  puVar4 = unaff_BP + 1;
  *unaff_BP = *puVar5;
  *puVar4 = 0x20;
  for (iVar7 = 10; puVar4 = puVar4 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0;
  }
  return CONCAT22(in_stack_00000016,in_stack_0000001a);
}


