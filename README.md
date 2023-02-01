# SPDX-Converter
Takes in json files and outputs them in the spdx file format.
- This is currently only built for json files created by Microsoft's [sbom-tool](https://github.com/microsoft/sbom-tool).
- The output spdx format is targeted to work with nyph-infosec's [daggerboard tool](https://github.com/nyph-infosec/daggerboard)
-  Information about the SPDX format can be found here: [Using SPDX](https://spdx.dev/resources/use/).

## Instructions
---

To compile: 
- Ensure you're in the SPDX_CONVERTER directory
- Enter `$ make` in the terminal (don't include the '$')

To run: 
- Enter `$ ./run`  (don't include the '$')

Follow the instructions to convert your json file to an spdx file.

The spdx file will be in the Program_Output folder.

## Resources
---
- This project uses nlohmann's [Json Library](https://github.com/nlohmann/json)


<br><br>
** Note: The microsoft-sbom-tool(example).json was pulled from Microsoft's Open Source [sbom-tool](https://github.com/microsoft/sbom-tool). **
