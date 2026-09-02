/* 1000:416c */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_416c(void)

{
  uint uVar1;
  uint in_CX;
  undefined2 unaff_DS;
  
  uVar1 = func_0x0001adf9();
  uVar1 = (uint)(((ulong)uVar1 * 1000) / (ulong)in_CX);
  *(undefined2 *)0x1aa9 = CONCAT11((char)(uVar1 % 10),(char)(uVar1 / 10));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


