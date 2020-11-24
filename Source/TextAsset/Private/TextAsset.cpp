#include "TextAsset.h"
#include "EditorFramework/AssetImportData.h"
// #include "UObjectBaseUtility.h"

void UTextAsset::PostInitProperties()
{
#if WITH_EDITORONLY_DATA
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        AssetImportData = NewObject<UAssetImportData>(this, TEXT("AssetImportData"));
    }
#endif
    Super::PostInitProperties();
}
