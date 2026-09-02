/* 1000:9527 */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_9527(void)

{
  code *pcVar1;
  undefined2 *unaff_BP;
  undefined2 unaff_SS;
  
  *unaff_BP = 0x952b;
  FUN_1000_6065();
  unaff_BP[-1] = 0x952e;
  FUN_1000_416c();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


