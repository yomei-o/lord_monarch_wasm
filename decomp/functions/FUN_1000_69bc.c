/* 1000:69bc */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_69bc(undefined1 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 in_DX;
  char cVar4;
  int in_BX;
  int unaff_BP;
  uint uVar5;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  uint *in_stack_00000000;
  
  *(uint *)(param_1 + unaff_BP + -0xc) =
       (*(int *)(param_1 + unaff_BP + -0xc) - (int)param_1) - (uint)in_CF;
  cVar4 = (char)((uint)in_DX >> 8) + *(char *)((int)in_stack_00000000 + in_BX + 0x1c10);
  if (-1 < cVar4) {
    uVar2 = in_stack_00000000[0x20];
    uVar3 = in_stack_00000000[0x10];
    uVar1 = *in_stack_00000000;
    uVar5 = ~(uVar1 & uVar3 & uVar2 & CONCAT11(cVar4,(char)in_DX));
    out(0x7e,(char)uVar1);
    out(0x7e,(char)uVar3);
    out(0x7e,(char)uVar2);
    out(0x7e,(char)in_DX);
    *param_1 = (char)uVar5;
    out(0x7e,(char)(uVar1 >> 8));
    out(0x7e,(char)(uVar3 >> 8));
    out(0x7e,(char)(uVar2 >> 8));
    out(0x7e,cVar4);
    param_1[1] = (char)(uVar5 >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


