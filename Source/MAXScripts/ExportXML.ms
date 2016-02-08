-- http://www.scriptspot.com/Tutorials/MAXScript%20Coding%20Standards.htm
/*
Find all assests
  this is $*
*/

ClearListener()

dir = "D:\\Projects\\Games\\Engine2\\Source\\Data\\NWN\\slaad\\"
makeDir dir

baseDir = getSavePath caption:"Save Path" initialDir:dir
files = #()
struct sceneAsset (name1,type,file)
fileCount = 1


fn determinant &a n = 
(
	det = 0.0
	m = BigMatrix n n

 	if n < 1 then
	( /* Error */
	)
	else if n == 1 then
	( /* Shouldn't get used */
		det = a[1][1];
	)
	else if n == 2 then
	(
		det = a[1][1] * a[2][2] - a[2][1] * a[1][2];
	)
	else
	(
		det = 0;
		for j1 = 1 to n do
		(
			for i = 2 to n do
			(
				j2 = 1
				for j = 1 to n do
				(
					if j == j1 then
					(
						continue
					)
					m[i-1][j2] = a[i][j]
					j2 = j2 + 1
				)
			)
			det = det + ((-1.0)^(j1 + 2.0) * a[1][j1] * determinant &m (n - 1))
		)
	)
	return det
)

fn coFactor &a n &b = 
(
	det = 0.0
	c = BigMatrix n n

	for j = 1 to n do
	(
		for i = 1 to n do
		( /* Form the adjoint a_ij */
			i1 = 1
			for ii = 1 to n do
			(
				if ii == i then
				(
					continue
				)
				j1 = 1
				for jj = 1 to n do
				(
					if jj == j then
					(
						continue
					)
					c[i1][j1] = a[ii][jj]
					j1 = j1 + 1
				)
				i1 = i1 + 1
			)

			/* Calculate the determinate */
			det = determinant &c  (n - 1)

			/* Fill in the elements of the coFactor */
			b[i][j] = (-1.0)^(i + j + 2.0) * det
		)
	)
)

fn transposeBM &a n = 
(
	tmp = BigMatrix n n

	for i = 2 to n do
	(
		for j = 1 to i do
		(
			tmp = a[i][j]
			a[i][j] = a[j][i]
			a[j][i] = tmp
		)
	)
)
	
fn inverseBM mat = 
(
	size = 4
	cf = BigMatrix size size
	inv = BigMatrix size size

	if mat != undefined then
	(
		-- to find out Determinant
		det = determinant &mat size

		coFactor &mat size &cf
		   
		-- inv = transpose of cofactor / Determinant
		for i = 1 to size do
		(
			for j = 1 to size do
			(
				inv[j][i] = cf[i][j] / det;
			)
		)
	)
	return inv
)
	
progressStart "Exporting Scene to XML"

fn printName obj output_file = 
(
	format "\t<Name>\n" to:output_file
	format "\t\t%\n" obj.name to:output_file
	format "\t</Name>\n" to:output_file
)

fn printMatrixRow row output_file =
(
	format "\t\t\t\t<p1>%</p1>\n" row.x to:output_file
	format "\t\t\t\t<p2>%</p2>\n" row.y to:output_file
	format "\t\t\t\t<p3>%</p3>\n" row.z to:output_file
)

-- http://www.gamedev.net/topic/209830-converting-coordinate-systems-3ds-max-gtopengl/
fn printMatrix xMat output_file =
(
	ToOpenGLAxis = matrix3 [-1,0,0] [0,0,1] [0,1,0] [0,0,0] -- (-1 * x), z, y
 	--ToOpenGLAxis = matrix3 [0,-1,0][0,0,-1][-1,0,0][0,0,0]
 	--ToOpenGLAxis = matrix3 [1,0,0][0,1,0][0,0,1][0,0,0]
  	--xMat = xMat * ToOpenGLAxis
	--xMat = inverse xMat
 	mat = BigMatrix 4 4
	mat[1][1] = xMat.row1.x
	mat[1][2] = xMat.row1.y
	mat[1][3] = xMat.row1.z
	mat[1][4] = 0
	mat[2][1] = xMat.row2.x
	mat[2][2] = xMat.row2.y
	mat[2][3] = xMat.row2.z
	mat[2][4] = 0
	mat[3][1] = xMat.row3.x
	mat[3][2] = xMat.row3.y
	mat[3][3] = xMat.row3.z
	mat[3][4] = 0
	mat[4][1] = xMat.row4.x
	mat[4][2] = xMat.row4.y
	mat[4][3] = xMat.row4.z
	mat[4][4] = 1
 	--mat = inverseBM mat
	
	--FixCoordSys &mat
	
	for r = 1 to mat.rows do
	(
		format "\t\t\t<r%>\n" r to:output_file
		for c = 1 to mat.columns do
		(
			format "\t\t\t\t<p%>" c to:output_file
			format "%" mat[r][c] to:output_file
			format "</p%>\n" c to:output_file
		)
		format "\t\t\t</r%>\n" r to:output_file
	)
)

fn printPoint pt output_file =
(
	format "\t\t\t<x>%</x>\n" pt.x to:output_file
	format "\t\t\t<y>%</y>\n" pt.y to:output_file
	format "\t\t\t<z>%</z>\n" pt.z to:output_file
)

--http://docs.autodesk.com/3DSMAX/15/ENU/MAXScript-Help/index.html?url=files/GUID-3B001F21-8FE9-4663-A972-E648682A0ACD.htm,topicNumber=d30e272529
fn printPos obj output_file cord:#parent =
(	
	in coordsys cord
	(
		format "\t<Matrix>\n" to:output_file
		format "\t\t<Transform>\n" to:output_file
		printMatrix obj.transform output_file
		format "\t\t</Transform>\n" to:output_file

		format "\t\t<Position>\n" to:output_file
		printPoint obj.transform.translationpart output_file
		format "\t\t</Position>\n" to:output_file
		
		cName = classof obj
	--	format "%" cName
		try
		(
			rot = quatToEuler2 obj.transform.rotation
			format "\t\t<Rotation>\n" to:output_file
			printPoint rot output_file
-- 			format "\t\t\t<x>%</x>\n" obj.rotation.x_rotation to:output_file
-- 			format "\t\t\t<y>%</y>\n" obj.rotation.y_rotation to:output_file
-- 			format "\t\t\t<z>%</z>\n" obj.rotation.z_rotation to:output_file

--			printPoint obj.transform.rotationpart.axis output_file
--			format "\t\t\t<a>%</a>\n" obj.transform.rotationpart.angle to:output_file
			format "\t\t\t<a>%</a>\n" obj.transform.rotation.angle to:output_file
			format "\t\t</Rotation>\n" to:output_file
		)
		catch()
		format "\t\t<Scale>\n" to:output_file
		printPoint  obj.transform.scalepart output_file
		format "\t\t</Scale>\n" to:output_file
		format "\t\t<Pivot>\n" to:output_file
		printPoint obj.pivot output_file
		format "\t\t</Pivot>\n" to:output_file
		
		format "\t</Matrix>\n" to:output_file

		format "\t<Offset_Matrix>\n" to:output_file
		format "\t\t<Transform>\n" to:output_file
		printMatrix obj.objectTransform output_file
		format "\t\t</Transform>\n" to:output_file

		format "\t\t<Position>\n" to:output_file
		printPoint obj.objectoffsetpos output_file
		format "\t\t</Position>\n" to:output_file
		try
		(
			format "\t\t<Rotation>\n" to:output_file
			printPoint obj.objectoffsetrot output_file
			format "\t\t\t<a>%</a>\n" obj.objectoffsetrot.angle to:output_file
			format "\t\t</Rotation>\n" to:output_file
		)
		catch()
		format "\t\t<Scale>\n" to:output_file
		printPoint obj.objectoffsetscale output_file
		format "\t\t</Scale>\n" to:output_file
		format "\t</Offset_Matrix>\n" to:output_file
	)
)

fn printKeys ctrl output_file =
(
	format "ctrl: % = \n" ctrl
	if ctrl != undefined then
	(
		format "%" ctrl.value

		if ctrl.supportsKeys then
		(
			format "Supports Keys\n"
			keyCount = numkeys ctrl
			format "Key Count:%\n" keyCount
			for k = 1 to keyCount do
			(
				key = getKey ctrl k
				format "key:%\n" key
				keyTime = getKeyTime ctrl k
				format "Key Time:%\n" keyTime
				format "Key value: %\n" key.value
				if (numEaseCurves ctrl) > 0 then
				(
					format "Ease Curve:%" ctrl.Ease_Curve
				)
				if (numMultiplierCurves ctrl) > 0 then
				(
					format "Multiplier Curve:%" ctrl.Multiplier_Curve
				)
			)
		)
	)
)

fn printAnimation obj output_file grp =
(
	in coordsys #parent 
	(
		format "\t<Animation>\n" to:output_file
		try
		(
	-- 					keyTime = getKeyTime ctrl f
	-- 					format "\t\t\t<Frame_Number>%</Frame_Number>\n" keyTime to:output_file
	-- 					format "\t\t\t<Value>%</Value>\n" key.value to:output_file

	-- 					format "\t\t\t<In_Tangent>%</In_Tangent>\n" key.inTangent to:output_file -- float or point3 (see below)
	-- 					format "\t\t\t<Out_Tangent>%</Out_Tangent>\n" key.outTangent to:output_file -- float or point3 (see below)
	-- 					format "\t\t\t<In_Tangent_Type>%</In_Tangent_Type>\n" key.inTangentType to:output_file -- see list of permitted names below
	-- 					format "\t\t\t<Out_Tangent_Type>%</Out_Tangent_Type>\n" key.outTangentType to:output_file -- see list of permitted names below
	-- 					format "\t\t\t<In_Tangent_Length>%</In_Tangent_Length>\n" key.inTangentLength to:output_file
	-- 					format "\t\t\t<Out_Tangent_Length>%</In_Tangent_Length>\n" key.outTangentLength to:output_file
			lastTransform = matrix3 [0,0,0][0,0,0][0,0,0][0,0,0]
			baseTransform = inverse obj.transform
			index = 0
			format "\t\t<Start_Frame>%</Start_Frame>\n" animationrange.start to:output_file
			format "\t\t<End_Frame>%</End_Frame>\n" animationrange.end to:output_file
			
			if obj.isAnimated then
			(
				format "is animated:%\n" obj.name
				format "----Position %\n" obj.position
				ctrls = getXYZControllers obj.position.controller
				for i = 1 to ctrls.count do
				(
					printKeys ctrls[i] output_file
				)
				format "----Rotation %\n" obj.rotation
				ctrls = getXYZControllers obj.rotation.controller
				for i = 1 to ctrls.count do
				(
					printKeys ctrls[i] output_file
				)
				format "----Scale %\n" obj.scale
				ctrls = getXYZControllers obj.scale.controller
				for i = 1 to ctrls.count do
				(
					printKeys ctrls[i] output_file
				)
			)
			
			for t = animationrange.start to animationrange.end do
			(
-- 				index = index + 1
-- 				per = index/animationrange.end
-- 				percent = percent + (per*2 )
-- 				progressUpdate percent

				at time t
				(
					tmp = copy obj.transform
	 				if grp == 1 then
	 				(
	 					offset = obj.transform * baseTransform
	 					obj.transform = offset
					)
					
					if lastTransform as String != obj.transform as String then
					(
						format "\t\t<Frame>\n" to:output_file
						format "\t\t\t<Frame_Number>%</Frame_Number>\n" t to:output_file
						
						printPos obj output_file

						--format "%\n% T\n" lastTransform obj.transform					

						lastTransform = copy obj.transform

						format "\t\t</Frame>\n" to:output_file
					)
					else
					(
						--format "%\n% F\n" lastTransform obj.transform
					)
					obj.transform = copy tmp
				)
			)
		)
		catch
		(
			format "No animation on: %\n" obj.name
			format "*** % ***\n" (getCurrentException())
		)
		format "\t</Animation>\n" to:output_file
	)
)

fn printPosition obj output_file cord:#parent =
(
	if isGroupMember obj then
	(
		myObj = obj
		-- TODO : needs to support nested groups
		while (isGroupMember myObj) do 
				myObj=myObj.parent

		tmp = copy obj.transform
		offset = inverse myObj.transform
		offset = obj.transform * offset
		obj.transform = offset
		printPos obj output_file
		obj.transform = copy tmp

		format "\t\t<Group_Name>%</Group_Name>\n" myObj.name to:output_file
		makeDir (baseDir + "/Groups/")
		fileName = (baseDir + "/Groups/" + myObj.name + ".xml")
		out_file = createfile fileName
		grpA = sceneAsset name1:myObj.Name type:"group" file:fileName
		files[fileCount] = grpA
		fileCount = fileCount + 1

		format "\t<Group>\n" to:out_file
		printName myObj out_file
		printPos myObj out_file
		printAnimation myObj out_file 1
		format "\t</Group>\n" to:out_file

		close out_file
	)
	else
	(
		printPos obj output_file
	)
)


fn printColor obj output_file =
(
	format "\t<Color>\n" to:output_file
	format "\t\t<r>%</r>\n" (obj.r/255.0) to:output_file
	format "\t\t<g>%</g>\n" (obj.g/255.0) to:output_file
	format "\t\t<b>%</b>\n" (obj.b/255.0) to:output_file
	format "\t\t<a>%</a>\n" (obj.a/255.0) to:output_file
	format "\t</Color>\n" to:output_file
)

fn printTexture txt output_file =
(
	format "\t\t\t<Name>%</Name>\n" txt.name to:output_file
	
	makeDir (baseDir + "/Textures/")
	fileName = (baseDir + "/Textures/" + txt.name + ".xml")
	out_file = createfile fileName
	txtA = sceneAsset name1:txt.Name type:"texture" file:fileName
	files[fileCount] = txtA
	fileCount = fileCount + 1
	format "<Texture>\n" to:out_file
	format "\t<Name>\n" to:out_file
	format "\t\t%\n" txt.name to:out_file
	format "\t</Name>\n" to:out_file
	format "\t\t\t<FileName>%</FileName>\n" txt.filename to:out_file
	format "\t\t\t<StartTime>%</StartTime>\n" txt.starttime to:out_file
	format "\t\t\t<PlaybackRate>%</PlaybackRate>\n" txt.playbackrate to:out_file
	format "\t\t\t<EndCondition>%</EndCondition>\n" txt.endcondition to:out_file
--	end condition values:
--	0-Loop (Causes the animation to loop over and over again.)
--	1-Ping Pong (Causes the animation to be played backwards, making every animated sequence "loop smoothly")
--	2-Hold (Causes the last frame of the animation to be frozen on the surface until the end of the scene.)
	format "</Texture>\n" to:out_file
	close out_file
)

fn printMaterial mat =
(
	makeDir (baseDir + "/Materials/")
	fileName = (baseDir + "/Materials/" + mat.Name + ".xml")
	out_file = createfile fileName
	matA = sceneAsset name1:mat.Name type:"material" file:fileName
	files[fileCount] = matA
	fileCount = fileCount + 1
	format "<Material>\n" to:out_file
	format "\t<Name>\n" to:out_file
	format "\t\t%\n" mat.Name to:out_file
	format "\t</Name>\n" to:out_file
	try(format "\t<Shader_Type>%</Shader_Type>\n" mat.shaderType to:out_file)catch()
	try(format "\t<Two_Sided>%</Two_Sided>\n" mat.twoSided to:out_file)catch()
	try(format "\t<Faceted>%</Faceted>\n" mat.faceted to:out_file)catch()
	try(format "\t<Soften>%</Soften>\n" mat.soften to:out_file)catch()
	try(format "\t<Index_Of_Refraction>%</Index_Of_Refraction>\n" mat.ior to:out_file)catch() -- index of refraction
	format "\t<Ambient>\n" to:out_file
	try(printColor mat.ambient out_file)catch()
	try(if 	mat.ambientMapEnable do
	(
		format "\t\t<Ambient_Map>\n" to:out_file
		printTexture mat.ambientMap out_file
		format "\t\t</Ambient_Map>\n" to:out_file
		format "\t\t<Ambient_Map_Amount>%</Ambient_Map_Amount>\n" mat.ambientMapAmount to:out_file
	))catch()
	format "\t</Ambient>\n" to:out_file
	format "\t<Diffuse>\n" to:out_file
	try(printColor mat.diffuse out_file)catch()
	try(if mat.diffuseMapEnable do
	(
		format "\t\t<Diffuse_Map>\n" to:out_file
		printTexture mat.diffuseMap out_file
		format "\t\t</Diffuse_Map>\n" to:out_file
		format "\t\t<Diffuse_Map_Amount>%</Diffuse_Map_Amount>\n" mat.diffuseMapAmount to:out_file
	))catch()
	format "\t</Diffuse>\n" to:out_file
	format "\t<Specular>\n" to:out_file
	try(printColor mat.specular out_file)catch()
	try(format "\t\t<Specular_Level>%</Specular_Level>\n" mat.specularLevel to:out_file)catch()
	try(if mat.specularMapEnable do
	(
		format "\t\t<Specular_Map>\n" to:out_file
		printTexture mat.specularMap out_file
		format "\t\t</Specular_Map>\n" to:out_file
		format "\t\t<Specular_Map_Amount>%</Specular_Map_Amount>\n" mat.specularMapAmount to:out_file
	))catch()
	format "\t</Specular>\n" to:out_file
	try(format "\t<Glossiness>%</Glossiness>\n" (mat.glossiness/100 * 128) to:out_file)catch()
	try(if mat.glossinessMapEnable do
	(
		format "\t<Glossiness_Map>\n" to:out_file
		printTexture mat.glossinessMap out_file
		format "\t</Glossiness_Map>\n" to:out_file
		format "\t<Glossiness_Map_Amount>%</Glossiness_Map_Amount>\n" mat.glossinessMapAmount to:out_file
	))catch()
	format "\t<Self_Illum>\n" to:out_file
	try(format "\t\t<Self_Illum_Amount>%</Self_Illum_Amount>\n" mat.selfIllumAmount to:out_file)catch()
	try(if mat.useSelfIllumColor do
	(
		format "\t\t<Self_Illum_Color>\n" to:out_file
		printColor mat.selfIllumColor out_file
		format "\t\t</Self_Illum_Color>\n" to:out_file
	))catch()
	try(if mat.selfIllumMapEnable do
	(
		format "\t\t<Self_Illum_Map>\n" to:out_file
		printTexture mat.selfIllumMap out_file
		format "\t\t</Self_Illum_Map>\n" to:out_file
		format "\t\t<Self_Illum_Map_Amount>%</Self_Illum_Map_Amount>\n" mat.selfIllumMapAmount to:out_file
	))catch()
	format "\t</Self_Illum>\n" to:out_file

	try(format "\t<Opacity>%</Opacity>\n" (mat.opacity/100) to:out_file)catch()
	try(format "\t<Opacity_Type>%</Opacity_Type>\n" mat.opacityType to:out_file)catch()
	try(format "\t<Opacity_Fall_Off>%</Opacity_Fall_Off>\n" mat.opacityFallOff to:out_file)catch()
	try(format "\t<Opacity_Fall_Off_Type>%</Opacity_Fall_Off_Type>\n" mat.opacityFallOffType to:out_file)catch()
	try(if mat.opacityMapEnable do
	(
		format "\t<Opacity_Map>\n" to:out_file
		printTexture mat.opacityMap out_file
		format "\t</Opacity_Map>\n" to:out_file
		format "\t<Opacity_Map_Amount>%</Opacity_Map_Amount>\n" mat.opacityMapAmount to:out_file
	))catch()
	--mat.filter
	--mat.filterColor
	try(if mat.filterMapEnable do
	(
		format "\t<Filter_Map>\n" to:out_file
		printTexture mat.filterMap out_file
		format "\t</Filter_Map>\n" to:out_file
		format "\t<Filter_Map_Amount>%</Filter_Map_Amount>\n" mat.filterMapAmount to:out_file
	))catch()
	try(if mat.bumpMapEnable do
	(
		format "\t<Bump_Map>\n" to:out_file
		printTexture mat.bumpMap out_file
		format "\t</Bump_Map>\n" to:out_file
		format "\t<Bump_Map_Amount>%</Bump_Map_Amount>\n" mat.bumpMapAmount to:out_file
	))catch()
	try(if mat.reflectionMapEnable do
	(
		format "\t<Reflection_Level>%</Reflection_Level>\n" mat.reflectionLevel to:out_file
		format "\t<Reflection_Map>\n" to:out_file
		printTexture mat.reflectionMap out_file
		format "\t</Reflection_Map>\n" to:out_file
		format "\t<Reflection_Map_Amount>%</Reflection_Map_Amount>\n" mat.reflectionMapAmount to:out_file
	))catch()
	try(if mat.refractionMapEnable do
	(
		format "\t<Refraction_Map>\n" to:out_file
		printTexture mat.refractionMap out_file
		format "\t</Refraction_Map>\n" to:out_file
		format "\t<Refraction_Map_Amount>%</Refraction_Map_Amount>\n" mat.refractionMapAmount to:out_file
	))catch()
	try(if mat.displacementMapEnable do
	(
		format "\t<Displacement_Map>\n" to:out_file
		printTexture mat.displacementMap out_file
		format "\t</Displacement_Map>\n" to:out_file
		format "\t<Displacement_Map_Amount>%</Displacement_Map_Amount>\n" mat.displacementMapAmount to:out_file
	))catch()
	format "</Material>\n" to:out_file
	close out_file
)

percent = 10
progressUpdate percent
/*
switch on camera
	trans
	rot
	scale
	lens
	fov
	orthoPro
	nearRange
	farRange
	nearClip
	farClip
	target
*/
index = 0
for obj in cameras do
(
	index = index + 1
	per = index/cameras.count
	percent = percent + (per*10)
	progressUpdate percent

	makeDir (baseDir + "/Cameras/")
	fileName = (baseDir + "/Cameras/" + obj.Name + ".xml")
	output_file = createfile fileName
	cam = sceneAsset name1:obj.Name type:"camera" file:fileName
	files[fileCount] = cam
	fileCount = fileCount + 1
	format "<Camera>\n" to:output_file
	
	printName obj output_file
	
	if (findString obj.name "Target") == undefined do
	(
		format "\t<Type>\n\t\t%\n\t</Type>\n" obj.type to:output_file
	)
	
	printPosition obj output_file
	
	if (findString obj.name "Target") == undefined do
	(
		format "\t<FOV>%</FOV>\n" obj.fov to:output_file
		format "\t<FOV_Type>%</FOV_Type>\n" obj.fovType to:output_file
		--format "\t%\n" obj.orhtoProjection to:output_file
		format "\t<Near_Range>%</Near_Range>\n" obj.nearrange to:output_file
		format "\t<Far_Range>%</Far_Range>\n" obj.farrange to:output_file
		format "\t<Clip_Manually>%</Clip_Manually>\n" obj.clipManually to:output_file
		format "\t<Near_Clip>%</Near_Clip>\n" obj.nearclip to:output_file
		format "\t<Far_Clip>%</Far_Clip>\n" obj.farclip to:output_file
		format "\t<Target_Distance>%</Target_Distance>\n" obj.targetDistance to:output_file
	)
	printAnimation obj output_file 0
	format "</Camera>\n" to:output_file
	close output_file
)

percent = 30
progressUpdate percent
/*
switch on light
	trans
	rot
	scale
	type
	shadows
	multiplier
	color
	useAtten
	nearAtten
	farAtten
	hotSpot
	fallOff
	shape
	projectMap
*/
index = 0
for obj in lights do
(
	index = index + 1
	per = index/lights.count
	percent = percent + (per*30)
	progressUpdate percent

	makeDir (baseDir + "/Lights/")
	fileName = (baseDir + "/Lights/" + obj.Name + ".xml")
	output_file = createfile fileName
	lite = sceneAsset name1:obj.Name type:"light" file:fileName
	files[fileCount] = lite
	fileCount = fileCount + 1
	format "<Light>\n" to:output_file
	
	printName obj output_file
	printPosition obj output_file
	
	try (format "\t<Type>%</Type>\n" obj.type to:output_file) catch()
	format "\t<Enabled>%</Enabled>\n" obj.enabled to:output_file
	try (printColor obj.rgb output_file) catch()
	try (format "\t<Multiplier>%</Multiplier>\n" obj.multiplier to:output_file) catch()
	try (format "\t<Contrast>%</Contrast>\n" obj.contrast to:output_file) catch()
	try (format "\t<Soften_Diffuse_Edge>%</Soften_Diffuse_Edge>\n" obj.softenDiffuseEdge to:output_file) catch()
	try (format "\t<Affect_Diffuse>%</Affect_Diffuse>\n" obj.affectDiffuse to:output_file) catch()
	try (format "\t<Affect_Specular>%</Affect_Specular>\n" obj.affectSpecular to:output_file) catch()
	try (format "\t<Ambient_Only>%</Ambient_Only>\n" obj.ambientOnly to:output_file) catch()
	try (format "\t<Projector>%</Projector>\n" obj.projector to:output_file) catch()
	try (format "\t<Projector_Map>%</Projector_Map>\n" obj.projectorMap to:output_file) catch()
	try (format "\t<Near_Atten_Start>%</Near_Atten_Start>\n" obj.nearAttenStart to:output_file) catch()
	try (format "\t<Near_Atten_End>%</Near_Atten_End>\n" obj.nearAttenEnd to:output_file) catch()
	try (format "\t<Use_Near_Atten>%</Use_Near_Atten>\n" obj.useNearAtten to:output_file) catch()
	try (format "\t<Far_Atten_Start>%</Far_Atten_Start>\n" obj.farAttenStart to:output_file) catch()
	try (format "\t<Far_Atten_End>%</Far_Atten_End>\n" obj.farAttenEnd to:output_file) catch()
	try (format "\t<Use_Far_Atten>%</Use_Far_Atten>\n" obj.useFarAtten to:output_file) catch()
	try (format "\t<Atten_Decay>%</Atten_Decay>\n" obj.attenDecay to:output_file) catch()
	try (format "\t<Decay_Radius>%</Decay_Radius>\n" obj.DecayRadius to:output_file) catch()
	
	try (format "\t<Cast_Shadows>%</Cast_Shadows>\n" obj.castShadows to:output_file) catch()
	format "\t<Shadow>\n" to:output_file
	try (format "\t\t<Generator>%</Generator>\n" obj.shadowGenerator to:output_file) catch()
	try (printColor obj.ShadowColor output_file) catch()
	try (format "\t\t<Multiplier>%</Multiplier>\n" obj.shadowMultiplier to:output_file) catch()
	format "\t</Shadow>\n" to:output_file

	printAnimation obj output_file 0
	format "</Light>" to:output_file
	close output_file
)

percent = 60
progressUpdate percent

/*
switch on model
	trans
	rot
	scale
	pivotPoint
	polys
		verts
*/
index = 0
for obj in geometry do
(
	index = index + 1
	per = index/geometry.count
	percent = percent + (per*20)
	progressUpdate percent

	makeDir (baseDir + "/Models/")
	fileName = (baseDir + "/Models/" + obj.Name + ".xml")
	output_file = createfile fileName
	geom = sceneAsset name1:obj.Name type:"model" file:fileName
	files[fileCount] = geom
	fileCount = fileCount + 1
	format "<Geometry>\n" to:output_file

	printName obj output_file
	printPosition obj output_file

	if obj.children.count > 0 do
	(
		format "\t<Children>\n" to:output_file
		for child in obj.children do
		(
			printName child output_file
		)
		format "\t</Children>\n" to:output_file
	)
	
	if obj.material != undefined do
	(
		format "\t<Material_Name>%</Material_Name>\n" obj.material.name to:output_file
		printMaterial obj.material
	)

	printAnimation obj output_file 0

	mat = copy obj.transform
	mat2 = obj.objectTransform
	
	inv = inverse obj.transform
	obj.transform = inv * mat
	--inv = inverse obj.objectTransform
	--obj.objectTransform = inv * mat2
	
	tmesh = snapshotAsMesh obj 
--	num_verts = tmesh.numverts 
	num_faces = tmesh.numfaces
	--output_mesh = createfile (baseDir + "/Models/Mesh/" + tmehs.Name + ".xml")
	format "\t<Mesh>\n" to:output_file
	
	in coordsys #local
	(
		for f = 1 to num_faces do
		(
			format "\t<Poly>\n" to:output_file
			face = getFace tmesh f
			norm = meshop.getFaceRNormals tmesh f
			txt = undefined
			try(txt = meshop.getMapFace tmesh 1 f )catch()
			matid = getFaceMatId tmesh f
			for v = 1 to 3 do
			(
				vert = getVert tmesh face[v]
				format "\t\t<Vert>\n" to:output_file
				printPoint vert output_file
				/*c = getVertColor tmesh face[1]
				printColor c
				*/
				format "\t\t\t<Normal>\n" to:output_file
				printPoint norm[v] output_file
				format "\t\t\t</Normal>\n" to:output_file
				
				if txt != undefined then
				(
					format "\t\t\t<Text_Coord>\n" to:output_file
					txtCoord = (meshOp.getMapVert tmesh 1 txt[v])
					format "\t\t\t\t<u>%</u>\n" txtCoord.x to:output_file
					format "\t\t\t\t<v>%</v>\n" txtCoord.y to:output_file
					format "\t\t\t\t<w>%</w>\n" txtCoord.z to:output_file
					format "\t\t\t</Text_Coord>\n" to:output_file
				)
				format "\t\t</Vert>\n" to:output_file
			)
			format "\t</Poly>\n" to:output_file
		)
		format "\t</Mesh>\n" to:output_file

		for b in systems do
		(
			format "\t<Bone>%</Bone\n" b.name to:output_file
		)
		
		format "</Geometry>" to:output_file
	)
	close output_file
	
	obj.transform = copy mat
	--obj.objectTransform = mat2
)

percent = 80
progressUpdate percent

-- scene file
output_file = createfile (baseDir + "/Scene.xml")
format "<Scene>\n" to:output_file
format "\t<Assets>\n" to:output_file
for i = 1 to files.count do
(
	per = i/files.count
	percent = percent + (per*20)
	progressUpdate percent
	format "\t\t<Asset>\n" to:output_file
	format "\t\t\t<Name>%</Name>\n" files[i].name1 to:output_file
	format "\t\t\t<Type>%</Type>\n" files[i].type to:output_file
	format "\t\t\t<File>%</File>\n" files[i].file to:output_file
	format "\t\t</Asset>\n" to:output_file
)
format "\t</Assets>\n" to:output_file
format "</Scene>" to:output_file
close output_file

-- http://forums.cgsociety.org/archive/index.php/t-322642.html
fn getArrayOfMapVerts2VertsPOLY theObj theMapChannel =
(
	numMapVerts = polyOp.getNumMapVerts theObj theMapChannel
	mapVerts2Verts = for mv=1 to numMapVerts collect #()
	numMapFaces = polyOp.getNumMapFaces theObj theMapChannel
	for f = 1 to numMapFaces do 
	(
		theMapFace = polyOp.getMapFace theObj theMapChannel f
		polyFace = polyOp.getFaceVerts theObj f
		for mv=1 to theMapFace.count do
		(
			mapVert = theMapFace[mv]
			if findItem mapVerts2Verts[mapVert] polyFace[mv] == 0 do append mapVerts2Verts[mapVert] polyFace[mv]
		)
	)
	mapVerts2Verts
)

fn getArrayOfMapVerts2VertsMESH theObj theMapChannel =
(
	numMapVerts = meshOp.getNumMapVerts theObj theMapChannel
	mapVerts2Verts = for mv=1 to numMapVerts collect #()
	numMapFaces = meshOp.getNumMapFaces theObj theMapChannel
	for f = 1 to numMapFaces do
	(
		theMapFace = meshOp.getMapFace theObj theMapChannel f
		theMapFace = #(theMapFace.x as integer,theMapFace.y as integer,theMapFace.z as integer)
		meshFace = getFace theObj f
		meshFace = #(meshFace.x as integer,meshFace.y as integer,meshFace.z as integer)
		for mv=1 to theMapFace.count do
		(
			mapVert = theMapFace[mv]
			if findItem mapVerts2Verts[mapVert] meshFace[mv] == 0 do append mapVerts2Verts[mapVert] meshFace[mv]
		)
	)
	mapVerts2Verts
)

fn getArrayOfMapVerts2Verts theObj theMapChannel =
(
	array=false
	case classOf theObj of
	(
		Editable_mesh: array=getArrayOfMapVerts2VertsMESH theObj theMapChannel
		Editable_Poly: array=getArrayOfMapVerts2VertsPOLY theObj theMapChannel
	)
	array
)

fn getArrayOfVerts2MapVerts mapVerts2Verts =
(
	verts2MapVerts=#()
	for mv=1 to mapVerts2Verts.count do
	(
		currentVerts=mapVerts2Verts[mv]
		if currentVerts!=undefined do
		(
			for v=1 to currentVerts.count do
			(
				if verts2MapVerts[currentVerts[v]] == undefined
				then verts2MapVerts[currentVerts[v]]=#(mv)
				else append verts2MapVerts[currentVerts[v]] mv
			)
		)
	)
	verts2MapVerts
)

/*
clearListener()
if selection.count!=0 then
(
	obj=selection[1]
	channel=1
	mapVerts2Verts=getArrayOfMapVerts2Verts obj channel -- create the array mapVerts ==> verts
	if mapVerts2Verts!=false do
	(
		verts2MapVerts=getArrayOfVerts2MapVerts mapVerts2Verts -- create the array verts ==> mapVerts
		format"%\n" obj.name
		format "\narray : mapVerts2Verts\n======================\n"
		for i=1 to mapVerts2Verts.count do format "mapVert % => verts %\n" i mapVerts2Verts[i]
		format "\narray : verts2MapVerts\n======================\n"
		for i=1 to verts2MapVerts.count do format "vert % => mapVerts %\n" i verts2MapVerts[i]
	)
)
*/
progressEnd()