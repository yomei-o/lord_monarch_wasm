/* 1000:559b */

void FUN_1000_559b(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  iVar4 = FUN_1000_5a67();
  pbVar1 = (byte *)(unaff_BP + iVar4);
  bVar2 = *pbVar1;
  bVar3 = *pbVar1 + (byte)unaff_SI;
  *pbVar1 = bVar3 + in_CF;
  *(int *)0xe806 =
       (*(int *)0xe806 - unaff_SI) - (uint)(CARRY1(bVar2,(byte)unaff_SI) || CARRY1(bVar3,in_CF));
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


