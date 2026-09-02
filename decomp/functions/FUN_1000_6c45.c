/* 1000:6c45 */

void FUN_1000_6c45(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


