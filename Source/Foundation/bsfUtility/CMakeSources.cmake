set(BS_UTILITY_SRC_MATH
	"bsfUtility/Math/BsAABox.cpp"
	"bsfUtility/Math/BsDegree.cpp"
	"bsfUtility/Math/BsMath.cpp"
	"bsfUtility/Math/BsMatrix3.cpp"
	"bsfUtility/Math/BsMatrix4.cpp"
	"bsfUtility/Math/BsPlane.cpp"
	"bsfUtility/Math/BsQuaternion.cpp"
	"bsfUtility/Math/BsRadian.cpp"
	"bsfUtility/Math/BsRay.cpp"
	"bsfUtility/Math/BsSphere.cpp"
	"bsfUtility/Math/BsVector2.cpp"
	"bsfUtility/Math/BsVector2I.cpp"
	"bsfUtility/Math/BsVector3.cpp"
	"bsfUtility/Math/BsVector4.cpp"
	"bsfUtility/Math/BsBounds.cpp"
	"bsfUtility/Math/BsConvexVolume.cpp"
	"bsfUtility/Math/BsTorus.cpp"
	"bsfUtility/Math/BsRect3.cpp"
	"bsfUtility/Math/BsRect2.cpp"
	"bsfUtility/Math/BsRect2I.cpp"
	"bsfUtility/Math/BsLineSegment3.cpp"
	"bsfUtility/Math/BsCapsule.cpp"
	"bsfUtility/Math/BsLine2.cpp"
)

set(BS_UTILITY_INC_MATH
	"bsfUtility/Math/BsAABox.h"
	"bsfUtility/Math/BsDegree.h"
	"bsfUtility/Math/BsMath.h"
	"bsfUtility/Math/BsMatrix3.h"
	"bsfUtility/Math/BsMatrix4.h"
	"bsfUtility/Math/BsPlane.h"
	"bsfUtility/Math/BsQuaternion.h"
	"bsfUtility/Math/BsRadian.h"
	"bsfUtility/Math/BsRay.h"
	"bsfUtility/Math/BsSphere.h"
	"bsfUtility/Math/BsVector2.h"
	"bsfUtility/Math/BsVector2I.h"
	"bsfUtility/Math/BsVector3.h"
	"bsfUtility/Math/BsVector3I.h"
	"bsfUtility/Math/BsVector4.h"
	"bsfUtility/Math/BsVector4I.h"
	"bsfUtility/Math/BsBounds.h"
	"bsfUtility/Math/BsConvexVolume.h"
	"bsfUtility/Math/BsTorus.h"
	"bsfUtility/Math/BsLineSegment3.h"
	"bsfUtility/Math/BsRect3.h"
	"bsfUtility/Math/BsRect2.h"
	"bsfUtility/Math/BsRect2I.h"
	"bsfUtility/Math/BsCapsule.h"
	"bsfUtility/Math/BsMatrixNxM.h"
	"bsfUtility/Math/BsLine2.h"
	"bsfUtility/Math/BsSIMD.h"
	"bsfUtility/Math/BsRandom.h"
	"bsfUtility/Math/BsComplex.h"
)

source_group("Math" FILES ${BS_UTILITY_INC_MATH} ${BS_UTILITY_SRC_MATH})

set(BS_UTILITY_SRC
	${BS_UTILITY_SRC_MATH}
	${BS_UTILITY_INC_MATH}
)

# 先注释
#if(WIN32)
#	list(APPEND BS_UTILITY_SRC ${BS_UTILITY_SRC_WIN32})
#	list(APPEND BS_UTILITY_SRC ${BS_UTILITY_INC_WIN32})
#endif()
#
