/* 1000:8f5c */

/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_8f5c(void)

{
  char *pcVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  uint in_BX;
  int unaff_BP;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  byte bVar8;
  undefined2 in_stack_0000fffc;
  
  bVar8 = (byte)in_stack_0000fffc;
  in(0x32);
  puVar6 = (undefined2 *)*(undefined2 *)0x32ee;
  puVar3 = (undefined2 *)*(undefined2 *)0x32f0;
  iVar4 = *(int *)0x32ea;
  puVar5 = (undefined2 *)*(uint *)0x32e6;
  if (puVar5 == (undefined2 *)0x0) goto LAB_1000_8fb8;
  if ((int)puVar5 < 0) {
    puVar6 = (undefined2 *)-(int)puVar6;
    if (puVar5 < puVar6) {
      pcVar1 = (char *)((int)puVar6 + in_BX + 0x78);
      *pcVar1 = *pcVar1 + (char)puVar5 + '\x01';
      return CONCAT11((char)((uint)puVar5 >> 8),(char)puVar5 + '\x03');
    }
    goto LAB_1000_8fb8;
  }
  if (puVar5 < puVar6) goto LAB_1000_8fb8;
  if (((iVar4 == 0) || (-1 < iVar4)) ||
     (puVar5 = (undefined2 *)((int)puVar5 + iVar4), -1 < (int)puVar5)) {
    in_BX = in_BX | 8;
    bVar7 = puVar5 < puVar3;
    puVar5 = (undefined2 *)((int)puVar5 - (int)puVar3);
    if (bVar7) goto LAB_1000_8faf;
    out(0x32,(char)puVar5);
    *(undefined2 *)0x32ea = 0;
  }
  else {
LAB_1000_8faf:
    out(0x32,(char)puVar5);
    *(char *)(in_BX + (int)puVar6) = *(char *)(in_BX + (int)puVar6) + (char)puVar5;
    *(undefined2 *)0x55ea = puVar5;
    in_stack_0000fffc = unaff_ES;
  }
  bVar8 = (byte)in_stack_0000fffc;
  uVar2 = in(iVar4);
  *puVar3 = uVar2;
LAB_1000_8fb8:
  *(byte *)(unaff_BP + (int)puVar6) = *(byte *)(unaff_BP + (int)puVar6) ^ bVar8;
  in(iVar4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


