##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=My2DGameEngine
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/Volumes/Data/My2DGameEngine
ProjectPath            :=/Volumes/Data/My2DGameEngine/My2DGameEngine
IntermediateDirectory  :=../build-$(ConfigurationName)/My2DGameEngine
OutDir                 :=../build-$(ConfigurationName)/My2DGameEngine
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=meisamrce
Date                   :=13/04/2021
CodeLitePath           :="/Users/meisamrce/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -framework OpenGL
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/local/Cellar/glfw/3.3.3/include/ $(IncludeSwitch)/usr/local/Cellar/sdl2/2.0.14_1/include/SDL2/ $(IncludeSwitch)/usr/local/Cellar/devil/1.8.0_2/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glfw.3.3 $(LibrarySwitch)IL $(LibrarySwitch)ILU $(LibrarySwitch)SDL2 
ArLibs                 :=  "libglfw.3.3.dylib" "libIL.dylib" "libILU.dylib" "libSDL2.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/Cellar/glfw/3.3.3/lib/ $(LibraryPathSwitch)/usr/local/Cellar/sdl2/2.0.14_1/lib/ $(LibraryPathSwitch)/usr/local/Cellar/devil/1.8.0_2/lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/My2DGameEngine/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/My2DGameEngine"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/My2DGameEngine"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/My2DGameEngine/.d:
	@mkdir -p "../build-$(ConfigurationName)/My2DGameEngine"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(ObjectSuffix): Shader.cpp ../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Shader.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(DependSuffix): Shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(DependSuffix) -MM Shader.cpp

../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(PreprocessSuffix): Shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Shader.cpp$(PreprocessSuffix) Shader.cpp

../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(ObjectSuffix): Game.cpp ../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(DependSuffix) -MM Game.cpp

../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(PreprocessSuffix): Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Game.cpp$(PreprocessSuffix) Game.cpp

../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(ObjectSuffix): Main.cpp ../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(DependSuffix): Main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(DependSuffix) -MM Main.cpp

../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(PreprocessSuffix): Main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Main.cpp$(PreprocessSuffix) Main.cpp

../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(ObjectSuffix): Tools.cpp ../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Tools.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tools.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(DependSuffix): Tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(DependSuffix) -MM Tools.cpp

../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(PreprocessSuffix): Tools.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Tools.cpp$(PreprocessSuffix) Tools.cpp

../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(ObjectSuffix): Logger.cpp ../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Logger.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(DependSuffix): Logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(DependSuffix) -MM Logger.cpp

../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(PreprocessSuffix): Logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Logger.cpp$(PreprocessSuffix) Logger.cpp

../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(ObjectSuffix): Sprite.cpp ../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(DependSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(DependSuffix) -MM Sprite.cpp

../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(PreprocessSuffix): Sprite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Sprite.cpp$(PreprocessSuffix) Sprite.cpp

../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(ObjectSuffix): Camera2D.cpp ../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/My2DGameEngine/My2DGameEngine/Camera2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Camera2D.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(DependSuffix): Camera2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(DependSuffix) -MM Camera2D.cpp

../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(PreprocessSuffix): Camera2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/My2DGameEngine/Camera2D.cpp$(PreprocessSuffix) Camera2D.cpp


-include ../build-$(ConfigurationName)/My2DGameEngine//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


