/* 1000:6a2a */

void FUN_1000_6a2a(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}


