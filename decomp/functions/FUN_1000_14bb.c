/* 1000:14bb */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000114cc) overlaps instruction at (ram,0x000114cb)
    */

void FUN_1000_14bb(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined2 in_AX;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool bVar6;
  
  bVar6 = 0x41 < (byte)in_AX;
  bVar5 = (byte)((uint)in_AX >> 8);
  pbVar1 = (undefined *)&DAT_0000_1456 + unaff_DI;
  bVar2 = *pbVar1;
  bVar4 = *pbVar1 - bVar5;
  *pbVar1 = bVar4 - bVar6;
  bVar3 = *(byte *)(in_BX + unaff_SI);
  *(byte *)(in_BX + unaff_SI) =
       (byte)(CONCAT11(bVar2 < bVar5 || bVar4 < bVar6,bVar3) >> 3) | bVar3 << 6;
  *(byte *)(param_1 + unaff_SI) = *(byte *)(param_1 + unaff_SI) ^ 0x42;
  pbVar1 = (byte *)(param_1 + unaff_DI + 0x41f5);
  *pbVar1 = ~*pbVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


