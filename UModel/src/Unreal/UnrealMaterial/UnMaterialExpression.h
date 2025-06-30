#ifndef __UNMATERIAL_EXPRESSION_H__
#define __UNMATERIAL_EXPRESSION_H__

class UMaterialExpression : public UObject
{
        DECLARE_CLASS(UMaterialExpression, UObject)
        TYPE_FLAGS(TYPE_SilentLoad | TYPE_InlinePropDump);

    public:
        // ETK: Generated data
        int Index;
        FString ClassName;

        BEGIN_PROP_TABLE
            PROP_INT(Index)
            PROP_STRING(ClassName)
            PROP_DROP(Material)
            PROP_DROP(Function)
            PROP_DROP(EditorX)
            PROP_DROP(EditorY)
            PROP_DROP(Desc)
        END_PROP_TABLE
};

class UMaterialExpressionTextureBase : public UMaterialExpression
{
        DECLARE_CLASS(UMaterialExpressionTextureBase, UMaterialExpression)

    public:
        UTexture3* Texture;

        BEGIN_PROP_TABLE
            PROP_OBJ(Texture)
            PROP_DROP(SamplerType)
        END_PROP_TABLE
};

class UMaterialExpressionTextureSample : public UMaterialExpressionTextureBase
{
        DECLARE_CLASS(UMaterialExpressionTextureSample, UMaterialExpressionTextureBase)

    public:
        FExpressionInput Coordinates;

        BEGIN_PROP_TABLE
            PROP_STRUC(Coordinates, FExpressionInput)
            PROP_DROP(SamplerSource)
        END_PROP_TABLE
};

class UMaterialExpressionTextureSampleParameter : public UMaterialExpressionTextureSample
{
        DECLARE_CLASS(UMaterialExpressionTextureSampleParameter, UMaterialExpressionTextureSample)

    public:
        FName ParameterName;
        FName Group;

        BEGIN_PROP_TABLE
            PROP_NAME(ParameterName)
            PROP_NAME(Group)
            PROP_DROP(ExpressionGUID)
        END_PROP_TABLE
};

class UMaterialExpressionTextureSampleParameter2D : public UMaterialExpressionTextureSampleParameter
{
        DECLARE_CLASS(UMaterialExpressionTextureSampleParameter2D, UMaterialExpressionTextureSampleParameter)
};

class UMaterialExpressionParameter : public UMaterialExpression
{
        DECLARE_CLASS(UMaterialExpressionParameter, UMaterialExpression)

    public:
        FName ParameterName;
        FName Group;

        BEGIN_PROP_TABLE
            PROP_NAME(ParameterName)
            PROP_NAME(Group) // editoronly
            PROP_DROP(ExpressionGUID)
        END_PROP_TABLE
};

class UMaterialExpressionScalarParameter : public UMaterialExpressionParameter
{
        DECLARE_CLASS(UMaterialExpressionScalarParameter, UMaterialExpressionParameter)

    public:
        float DefaultValue;

        BEGIN_PROP_TABLE
            PROP_FLOAT(DefaultValue)
        END_PROP_TABLE
};

class UMaterialExpressionStaticBoolParameter : public UMaterialExpressionParameter
{
        DECLARE_CLASS(UMaterialExpressionStaticBoolParameter, UMaterialExpressionParameter)

    public:
        bool DefaultValue;

        BEGIN_PROP_TABLE
            PROP_BOOL(DefaultValue)
        END_PROP_TABLE
};

class UMaterialExpressionStaticSwitchParameter : public UMaterialExpressionStaticBoolParameter
{
        DECLARE_CLASS(UMaterialExpressionStaticSwitchParameter, UMaterialExpressionStaticBoolParameter)

    public:
        FExpressionInput A;
        FExpressionInput B;

        BEGIN_PROP_TABLE
            PROP_STRUC(A, FExpressionInput)
            PROP_STRUC(B, FExpressionInput)
        END_PROP_TABLE
};

class UMaterialExpressionVectorParameter : public UMaterialExpressionParameter
{
        DECLARE_CLASS(UMaterialExpressionVectorParameter, UMaterialExpressionParameter)

    public:
        FLinearColor DefaultValue;

        BEGIN_PROP_TABLE
            PROP_STRUC(DefaultValue, FLinearColor)
        END_PROP_TABLE
};

class UMaterialExpressionConstant : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionConstant, UMaterialExpression)

public:
    float R;

    BEGIN_PROP_TABLE
        PROP_FLOAT(R)
    END_PROP_TABLE
};


class UMaterialExpressionConstant2Vector : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionConstant2Vector, UMaterialExpression)

public:
    float R;
    float G;

    BEGIN_PROP_TABLE
        PROP_FLOAT(R)
        PROP_FLOAT(G)
    END_PROP_TABLE
};

class UMaterialExpressionConstant3Vector : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionConstant3Vector, UMaterialExpression)

public:
    FLinearColor Colour;
    float R;
    float G;
    float B;

    BEGIN_PROP_TABLE
        PROP_STRUC(Colour, FLinearColor)
        PROP_FLOAT(R)
        PROP_FLOAT(G)
        PROP_FLOAT(B)
    END_PROP_TABLE
};

class UMaterialExpressionCameraVector : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionCameraVector, UMaterialExpression)
};

class UMaterialExpressionReflectionVector : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionReflectionVector, UMaterialExpression)
};

class UMaterialExpressionTime : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionTime, UMaterialExpression)

public:
    bool bIgnorePause;

    BEGIN_PROP_TABLE
        PROP_BOOL(bIgnorePause)
    END_PROP_TABLE
};

class UMaterialExpressionLinearInterpolate : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionLinearInterpolate, UMaterialExpression)

public:
    FExpressionInput A;
    FExpressionInput B;
    FExpressionInput Alpha;

    BEGIN_PROP_TABLE
        PROP_STRUC(A, FExpressionInput)
        PROP_STRUC(B, FExpressionInput)
        PROP_STRUC(Alpha, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionMultiply : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionMultiply, UMaterialExpression)

public:
    FExpressionInput A;
    FExpressionInput B;

    BEGIN_PROP_TABLE
        PROP_STRUC(A, FExpressionInput)
        PROP_STRUC(B, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionDotProduct : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionDotProduct, UMaterialExpression)

public:
    FExpressionInput A;
    FExpressionInput B;

    BEGIN_PROP_TABLE
        PROP_STRUC(A, FExpressionInput)
        PROP_STRUC(B, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionAdd : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionAdd, UMaterialExpression)

public:
    FExpressionInput A;
    FExpressionInput B;

    BEGIN_PROP_TABLE
        PROP_STRUC(A, FExpressionInput)
        PROP_STRUC(B, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionSubtract : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionSubtract, UMaterialExpression)

public:
    FExpressionInput A;
    FExpressionInput B;

    BEGIN_PROP_TABLE
        PROP_STRUC(A, FExpressionInput)
        PROP_STRUC(B, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionPanner : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionPanner, UMaterialExpression)

public:
    FExpressionInput Coordinate;
    FExpressionInput Time;
    float SpeedX;
    float SpeedY;

    BEGIN_PROP_TABLE
        PROP_STRUC(Coordinate, FExpressionInput)
        PROP_STRUC(Time, FExpressionInput)
        PROP_FLOAT(SpeedX)
        PROP_FLOAT(SpeedY)
    END_PROP_TABLE
};

class UMaterialExpressionAppendVector : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionAppendVector, UMaterialExpression)

public:
    FExpressionInput A;
    FExpressionInput B;
    float SpeedX;
    float SpeedY;

    BEGIN_PROP_TABLE
        PROP_STRUC(A, FExpressionInput)
        PROP_STRUC(B, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionComponentMask : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionComponentMask, UMaterialExpression)

public:
    FExpressionInput Input;
    bool R;
    bool G;
    bool B;
    bool A;

    BEGIN_PROP_TABLE
        PROP_STRUC(Input, FExpressionInput)
        PROP_BOOL(R)
        PROP_BOOL(G)
        PROP_BOOL(B)
        PROP_BOOL(A)
    END_PROP_TABLE
};

class UMaterialExpressionTextureCoordinate : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionTextureCoordinate, UMaterialExpression)

public:
    int CoordinateIndex;
    float UTiling;
    float VTiling;

    BEGIN_PROP_TABLE
        PROP_INT(CoordinateIndex)
        PROP_FLOAT(UTiling)
        PROP_FLOAT(VTiling)
    END_PROP_TABLE
};

class UMaterialExpressionClamp : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionClamp, UMaterialExpression)

public:
    FExpressionInput Input;
    FExpressionInput Min;
    FExpressionInput Max;

    BEGIN_PROP_TABLE
        PROP_STRUC(Input, FExpressionInput)
        PROP_STRUC(Min, FExpressionInput)
        PROP_STRUC(Max, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionConstantClamp : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionConstantClamp, UMaterialExpression)

public:
    FExpressionInput Input;
    float Min;
    float Max;

    BEGIN_PROP_TABLE
        PROP_STRUC(Input, FExpressionInput)
        PROP_FLOAT(Min)
        PROP_FLOAT(Max)
    END_PROP_TABLE
};

class UMaterialExpressionFresnel : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionFresnel, UMaterialExpression)

public:
    FExpressionInput Normal;
    float Exponent;

    BEGIN_PROP_TABLE
        PROP_STRUC(Normal, FExpressionInput)
        PROP_FLOAT(Exponent)
    END_PROP_TABLE
};

class UMaterialExpressionOneMinus : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionOneMinus, UMaterialExpression)

public:
    FExpressionInput Input;

    BEGIN_PROP_TABLE
        PROP_STRUC(Input, FExpressionInput)
    END_PROP_TABLE
};

class UMaterialExpressionSine : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionSine, UMaterialExpression)

public:
    FExpressionInput Input;
    float Period;

    BEGIN_PROP_TABLE
        PROP_STRUC(Input, FExpressionInput)
        PROP_FLOAT(Period)
    END_PROP_TABLE
};

enum EMaterialVectorCoordTransform
{
    TRANSFORM_World,
    TRANSFORM_View,
    TRANSFORM_Local,
    TRANSFORM_Tangent
};

enum EMaterialVectorCoordTransformSource
{
    TRANSFORMSOURCE_World,
    TRANSFORMSOURCE_Local,
    TRANSFORMSOURCE_Tangent
};

class UMaterialExpressionTransform : public UMaterialExpression
{
    DECLARE_CLASS(UMaterialExpressionTransform, UMaterialExpression)

public:
    FExpressionInput Input;
    EMaterialVectorCoordTransform TransformType;
    EMaterialVectorCoordTransformSource TransformSourceType;

    BEGIN_PROP_TABLE
        PROP_STRUC(Input, FExpressionInput)
        PROP_ENUM2(TransformType, EMaterialVectorCoordTransform)
        PROP_ENUM2(TransformSourceType, EMaterialVectorCoordTransformSource)
    END_PROP_TABLE
};

#define REGISTER_EXPRESSION_CLASSES \
	REGISTER_CLASS(UMaterialExpressionTextureSample) \
    REGISTER_CLASS(UMaterialExpressionTextureSampleParameter) \
	REGISTER_CLASS(UMaterialExpressionTextureSampleParameter2D) \
	REGISTER_CLASS(UMaterialExpressionScalarParameter) \
	REGISTER_CLASS(UMaterialExpressionStaticBoolParameter) \
	REGISTER_CLASS(UMaterialExpressionStaticSwitchParameter) \
	REGISTER_CLASS(UMaterialExpressionVectorParameter) \
    REGISTER_CLASS(UMaterialExpressionConstant) \
    REGISTER_CLASS(UMaterialExpressionConstant2Vector) \
    REGISTER_CLASS(UMaterialExpressionConstant3Vector) \
    REGISTER_CLASS(UMaterialExpressionCameraVector) \
    REGISTER_CLASS(UMaterialExpressionReflectionVector) \
    REGISTER_CLASS(UMaterialExpressionTime) \
    REGISTER_CLASS(UMaterialExpressionLinearInterpolate) \
    REGISTER_CLASS(UMaterialExpressionMultiply) \
    REGISTER_CLASS(UMaterialExpressionDotProduct) \
    REGISTER_CLASS(UMaterialExpressionAdd) \
    REGISTER_CLASS(UMaterialExpressionSubtract) \
    REGISTER_CLASS(UMaterialExpressionPanner) \
    REGISTER_CLASS(UMaterialExpressionAppendVector) \
    REGISTER_CLASS(UMaterialExpressionComponentMask) \
    REGISTER_CLASS(UMaterialExpressionTextureCoordinate) \
    // ETK: Add these to import script
    REGISTER_CLASS(UMaterialExpressionClamp) \
    REGISTER_CLASS(UMaterialExpressionConstantClamp) \
    REGISTER_CLASS(UMaterialExpressionFresnel) \
    REGISTER_CLASS(UMaterialExpressionOneMinus) \
    REGISTER_CLASS(UMaterialExpressionSine)

#endif // __UNMATERIAL_EXPRESSION_H__
