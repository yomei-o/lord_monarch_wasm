/* 1000:967a */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_967a(void)

{
  char cVar1;
  byte bVar2;
  byte in_CH;
  byte extraout_DH;
  undefined2 in_BX;
  undefined1 uVar4;
  int iVar3;
  undefined2 *puVar5;
  undefined1 *puVar6;
  int *unaff_BP;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar4 = (undefined1)((uint)in_BX >> 8);
  puVar7 = (undefined2 *)*unaff_BP;
  *unaff_BP = -0x6982;
  func_0x000137b4();
  iVar3 = CONCAT11(uVar4,0x11);
  *puVar7 = unaff_SS;
  puVar5 = puVar7 + -1;
  puVar7[-1] = 0x968f;
  FUN_1000_5da4();
  puVar6 = (undefined1 *)((int)puVar5 + -2);
  *(undefined2 *)((int)puVar5 + -2) = 0x9692;
  cVar1 = func_0x0001a7aa();
  bVar2 = cVar1 + 1;
  *(int *)(iVar3 + 0x2ded) =
       (int)puVar6 + (uint)CARRY1(extraout_DH,in_CH) + *(int *)(iVar3 + 0x2ded);
  *(byte *)0x2aae = bVar2;
  *(byte *)0x2aaf = bVar2;
  *(byte *)0x2ded = *(byte *)0x2ded | bVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


