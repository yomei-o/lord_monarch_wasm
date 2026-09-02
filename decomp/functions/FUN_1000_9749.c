/* 1000:9749 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_9749(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  int in_CX;
  undefined2 **ppuVar4;
  undefined2 **unaff_BP;
  undefined2 **ppuVar5;
  undefined2 *puVar6;
  int *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 *puStack_2;
  
  do {
    ppuVar5 = unaff_BP;
    do {
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        puVar6 = (undefined2 *)(*unaff_SI * 0x55);
        *(byte *)((int)unaff_SI + (int)(puVar6 + 0x19)) =
             *(byte *)((int)unaff_SI + (int)(puVar6 + 0x19)) >> 1;
        puStack_2 = puVar6;
        FUN_1000_8bcb();
        bVar3 = (byte)in_CX;
        puStack_2 = (undefined2 *)0x975d;
        FUN_1000_39e9();
        FUN_1000_5ed7();
        func_0x00015d71();
        FUN_1000_3769();
        *(byte *)((int)puVar6 + 0xc15) = *(byte *)((int)puVar6 + 0xc15) & bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      ppuVar4 = &puStack_2;
      unaff_BP = &puStack_2;
      puStack_2 = ppuVar5;
      cVar1 = '\x01';
      do {
        ppuVar5 = ppuVar5 + -1;
        ppuVar4 = ppuVar4 + -1;
        *ppuVar4 = *ppuVar5;
        cVar1 = cVar1 + -1;
      } while ('\0' < cVar1);
      uVar2 = FUN_1000_8bd2();
      ppuVar5 = &puStack_2;
    } while (1 < uVar2);
  } while( true );
}


