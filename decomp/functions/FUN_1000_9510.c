/* 1000:9510 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_9510(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *unaff_BP;
  undefined2 *puVar5;
  undefined2 *puVar6;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined4 uVar7;
  
  puVar5 = (undefined2 *)*unaff_BP;
  *unaff_BP = 0x9516;
  FUN_1000_6070();
  puVar4 = unaff_BP + -1;
  unaff_BP[-1] = 0x9519;
  uVar7 = func_0x0001b577();
  iVar3 = (int)uVar7 + 1;
  *(undefined2 *)((int)puVar4 + -2) =
       CONCAT11((char)((uint)iVar3 >> 8),
                (char)iVar3 + ((char *)((int)puVar5 + (int)unaff_DI))[-0x54]);
  puVar6 = (undefined2 *)*puVar5;
  cVar2 = in((int)((ulong)uVar7 >> 0x10));
  *unaff_DI = cVar2 + '\x01';
  unaff_DI[1] = cVar2 + '\x01';
  *puVar5 = unaff_CS;
  *puVar6 = 0x952b;
  FUN_1000_6065();
  puVar6[-1] = 0x952e;
  FUN_1000_416c();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


