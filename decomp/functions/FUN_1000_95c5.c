/* 1000:95c5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00019607) */

void FUN_1000_95c5(void)

{
  char cVar1;
  undefined2 unaff_DS;
  
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


