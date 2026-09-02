/* 1000:9680 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_9680(void)

{
  char cVar1;
  byte bVar2;
  byte in_CH;
  byte extraout_DH;
  int in_BX;
  undefined2 *puVar3;
  undefined1 *puVar4;
  undefined2 *unaff_BP;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *unaff_BP = unaff_SS;
  puVar3 = unaff_BP + -1;
  unaff_BP[-1] = 0x968f;
  FUN_1000_5da4();
  puVar4 = (undefined1 *)((int)puVar3 + -2);
  *(undefined2 *)((int)puVar3 + -2) = 0x9692;
  cVar1 = func_0x0001a7aa();
  bVar2 = cVar1 + 1;
  *(int *)(in_BX + 0x2ded) =
       (int)puVar4 + (uint)CARRY1(extraout_DH,in_CH) + *(int *)(in_BX + 0x2ded);
  *(byte *)0x2aae = bVar2;
  *(byte *)0x2aaf = bVar2;
  *(byte *)0x2ded = *(byte *)0x2ded | bVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


