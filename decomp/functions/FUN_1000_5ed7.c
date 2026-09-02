/* 1000:5ed7 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_5ed7(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined1 in_AL;
  int in_CX;
  undefined2 *puVar3;
  undefined1 *unaff_SI;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  
  while( true ) {
    out(0xa0,in_AL);
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    puVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    in_AL = *puVar1;
  }
  func_0x0003bc3e();
  func_0x00015c60();
  puVar4 = (undefined2 *)0x0;
  for (puVar3 = (undefined2 *)&DAT_0000_3e80; puVar3 != (undefined2 *)0x0;
      puVar3 = (undefined2 *)((int)puVar3 + -1)) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = 0xffff;
  }
  func_0x00017290();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


