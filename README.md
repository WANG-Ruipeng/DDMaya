# DDMaya Visual Studio Project Setup

## 1. Configuration Setup
1. Open **Visual Studio** and load the `DDMaya` project.
2. Open **Configuration Manager**:
   - Set **Active Solution Platform** to `x64`.

## 2. General Project Settings
1. **Navigate to:** `Configuration Properties -> General`
   - Set **Configuration Type** to `Dynamic Library (.dll)`
2. **Navigate to:** `Configuration Properties -> Advanced`
   - Set **Target File Extension** to `.mll`

## 3. C/C++ Settings
1. **Navigate to:** `Configuration Properties -> C/C++ -> General`
   - Set **Additional Include Directories** to:
     ```
     [MayaInstallDir Path]\include;$(ProjectDir)include\
     ```
2. **Navigate to:** `Configuration Properties -> C/C++ -> Preprocessor`
   - Add **Preprocessor Definitions**:
     ```
     NT_PLUGIN
     ```
3. **Navigate to:** `Configuration Properties -> C/C++ -> Code Generation`
   - Set **Runtime Library** to:
     ```
     Multi-threaded Debug DLL (/MDd)
     ```

## 4. Linker Settings
1. **Navigate to:** `Configuration Properties -> Linker -> General`
   - Set **Additional Library Directories** to:
     ```
     [MayaInstallDir Path]\lib
     ```
   - Set **Output File** to:
     ```
     $(OutDir)$(ProjectName).mll
     ```
2. **Navigate to:** `Configuration Properties -> Linker -> Input`
   - Add **Additional Dependencies**:
     ```
     Foundation.lib;
     OpenMaya.lib;
     OpenMayaUI.lib;
     OpenMayaAnim.lib;
     OpenMayaFX.lib;
     OpenMayaRender.lib;
     Image.lib;
     opengl32.lib;
     ```

## 5. Final Steps
- Save all changes.
- Build the project to generate the `.mll` plugin file for Maya.
- Ensure that Maya's plugin path is correctly set to include the output directory of the build.
