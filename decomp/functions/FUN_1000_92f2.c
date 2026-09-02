/* 1000:92f2 */

/* WARNING: Instruction at (ram,0x00019358) overlaps instruction at (ram,0x00019357)
    */

void FUN_1000_92f2(void)

{
  uint *puVar1;
  code *pcVar2;
  undefined2 uVar3;
  int in_CX;
  int iVar4;
  undefined2 in_DX;
  char *in_BX;
  char *pcVar5;
  int unaff_BP;
  undefined2 *unaff_SI;
  uint *puVar6;
  char *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  char in_SF;
  char in_OF;
  unkbyte10 in_ST0;
  undefined4 uVar7;
  char *pcStack_8;
  int iStack_6;
  
  if (in_OF != in_SF) {
    pcVar2 = (code *)swi(0xfa);
    (*pcVar2)();
    FUN_1000_8da7();
    *(undefined2 *)0xd276 = 0x2ff8;
    *(undefined2 *)0xd27a = 0;
    FUN_1000_6184();
    puVar1 = (uint *)(unaff_BP + (int)unaff_SI);
    *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0xf;
    pcVar2 = (code *)swi(1);
    (*pcVar2)();
    return;
  }
  puVar6 = unaff_SI + 1;
  uVar3 = *unaff_SI;
  do {
    if ((char)in_DX != '\x01') {
      pcVar5 = (char *)CONCAT11(((char)((uint)in_BX >> 8) - *in_BX) - in_CF,(char)in_BX);
      *unaff_DI = *unaff_DI + (char)uVar3 + -1;
      goto LAB_1000_9363;
    }
    puVar6 = (uint *)((int)puVar6 + 1);
    pcStack_8 = in_BX;
    iStack_6 = in_CX;
    while (pcVar5 = pcStack_8, iStack_6 == 1) {
LAB_1000_9363:
      do {
      } while (*(uint *)0x3f1a < 0x500);
      iVar4 = 0x28;
      *(undefined2 *)0xd276 = 0xfa1;
      uVar3 = func_0x0001d42c();
      *(byte *)0xef83 = *(byte *)0xef83 ^ (byte)uVar3;
      pcVar5[(int)puVar6] = pcVar5[(int)puVar6] & (byte)iVar4;
      *puVar6 = *puVar6 & (CONCAT11((char)((uint)uVar3 >> 8),(byte)uVar3 + 0x39) |
                          *(uint *)(pcVar5 + (int)puVar6));
      if (iVar4 == 1) {
        *(unkbyte10 *)(unaff_BP + 0x33da) = in_ST0;
        func_0x00012562();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      pcVar2 = (code *)swi(0x58);
      (*pcVar2)();
    }
    in_CX = 0xcf;
    unaff_DI = (char *)0xa0;
    in_BX = pcStack_8;
    uVar7 = FUN_1000_6132();
    in_DX = (undefined2)((ulong)uVar7 >> 0x10);
    uVar3 = (undefined2)uVar7;
    *(undefined1 *)0xe820 = 0;
    in_CF = '\0';
  } while( true );
}


