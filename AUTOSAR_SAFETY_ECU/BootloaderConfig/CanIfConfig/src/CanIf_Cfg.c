extern void CanTp_RxIndication(PduIdType, const PduInfoType*);

const CanIf_RxPduConfigType CanIf_RxPduConfig[] = {
    {
        .CanIfRxPduCanId = 0x123,
        .CanIfRxPduCanIdType = CANIF_STANDARD,
        .CanIfRxPduDataLength = 8,
        .CanIfRxUserType = CANIF_UL_CANTP, // Upper layer
        .CanIfRxUserRxIndication = &CanTp_RxIndication, // Function pointer
        .CanIfRxPduId = 0
    }
};
