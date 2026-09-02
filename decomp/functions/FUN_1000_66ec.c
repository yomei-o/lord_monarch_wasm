/* 1000:66ec */

void FUN_1000_66ec(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}


