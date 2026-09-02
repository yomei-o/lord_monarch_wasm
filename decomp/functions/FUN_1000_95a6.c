/* 1000:95a6 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00019607) */

void FUN_1000_95a6(void)

{
  char cVar1;
  undefined2 *in_AX;
  byte in_CL;
  int in_BX;
  undefined2 *puVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uStack_4;
  
  *(byte *)(unaff_BP + -0x38) = *(byte *)(unaff_BP + -0x38) | (byte)((uint)in_AX >> 8);
  puVar2 = &uStack_4;
  cVar1 = '\t';
  do {
    in_AX = in_AX + -1;
    puVar2 = puVar2 + -1;
    *puVar2 = *in_AX;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  func_0x0001ea1e();
  *(byte *)(in_BX + 0x2595) = *(byte *)(in_BX + 0x2595) & in_CL;
  FUN_1000_3809();
  FUN_1000_5e0b();
  func_0x00016011();
  cVar1 = func_0x0001b618();
  *(char *)0x4017 = cVar1 + '*';
  FUN_1000_5e03();
  FUN_1000_5e03();
  func_0x00016009();
  cVar1 = func_0x00013310();
  *(char *)0x4020 = cVar1 + '\x01';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


