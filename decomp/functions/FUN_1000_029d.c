/* 1000:029d */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000103a0) overlaps instruction at (ram,0x0001039f)
    */
/* WARNING: Removing unreachable block (ram,0x000102f4) */
/* WARNING: Removing unreachable block (ram,0x00010312) */
/* WARNING: Removing unreachable block (ram,0x00010314) */
/* WARNING: Removing unreachable block (ram,0x00010319) */
/* WARNING: Removing unreachable block (ram,0x0001034f) */
/* WARNING: Removing unreachable block (ram,0x00010377) */
/* WARNING: Removing unreachable block (ram,0x00010387) */
/* WARNING: Removing unreachable block (ram,0x00010316) */
/* WARNING: Removing unreachable block (ram,0x0001039f) */
/* WARNING: Removing unreachable block (ram,0x000103a6) */
/* WARNING: Removing unreachable block (ram,0x000103a8) */
/* WARNING: Removing unreachable block (ram,0x000103b3) */
/* WARNING: Removing unreachable block (ram,0x000103be) */
/* WARNING: Removing unreachable block (ram,0x00010400) */
/* WARNING: Removing unreachable block (ram,0x000103c0) */
/* WARNING: Removing unreachable block (ram,0x000103f7) */
/* WARNING: Removing unreachable block (ram,0x000103c7) */
/* WARNING: Removing unreachable block (ram,0x000103d8) */
/* WARNING: Removing unreachable block (ram,0x000103ee) */
/* WARNING: Removing unreachable block (ram,0x000103f8) */
/* WARNING: Removing unreachable block (ram,0x000103ff) */
/* WARNING: Removing unreachable block (ram,0x0001040b) */
/* WARNING: Removing unreachable block (ram,0x0001041c) */
/* WARNING: Removing unreachable block (ram,0x00010420) */
/* WARNING: Removing unreachable block (ram,0x0001042a) */
/* WARNING: Removing unreachable block (ram,0x0001042d) */
/* WARNING: Removing unreachable block (ram,0x00010394) */
/* WARNING: Removing unreachable block (ram,0x000102ec) */
/* WARNING: Removing unreachable block (ram,0x00010396) */
/* WARNING: Removing unreachable block (ram,0x000103e1) */

undefined4
FUN_1000_029d(undefined2 param_1,int param_2,undefined2 param_3,byte *param_4,undefined2 *param_5,
             undefined2 param_6,int param_7)

{
  byte *pbVar1;
  undefined2 *puVar2;
  int in_DX;
  int iVar3;
  byte bVar4;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_GS;
  undefined2 in_stack_00000000;
  
  iVar3 = *(int *)(unaff_SI + 4);
  *(int *)(iVar3 + -0x1b82) = unaff_SI;
  iVar3 = in_DX - *(int *)(iVar3 + unaff_SI);
  pbVar1 = param_4;
  *pbVar1 = *pbVar1 & (byte)param_1;
  if ('\0' < (char)*pbVar1) {
    param_4[param_2] = param_4[param_2] + (char)((uint)param_1 >> 8);
    bVar4 = (byte)((uint)iVar3 >> 8);
    param_4[param_2] = param_4[param_2] ^ bVar4;
    for (; param_7 != 0; param_7 = param_7 + -1) {
      puVar2 = param_5;
      param_5 = param_5 + 1;
      *puVar2 = param_1;
    }
    *(undefined1 *)0x3c08 = 0;
    *(undefined2 *)0x3bc2 = 0xffff;
    *(char *)(param_2 + 0x10) = *(char *)(param_2 + 0x10) + bVar4;
    *(char *)(param_2 + (int)param_5) = *(char *)(param_2 + (int)param_5) + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return CONCAT22(iVar3,param_1);
}


