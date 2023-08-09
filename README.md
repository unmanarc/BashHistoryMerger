# BashHistoryMerger v1.0

Author: Aaron Mizrachi <aaron@unmanarc.com>

## Description
BashHistoryMerger is a tool to merge multiple bash history files based on timestamps. It allows you to combine different shell histories while maintaining temporal order.

## Installation
You can build the project using CMake as follows:

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel
make
make install
```

You can also install the RPM package if available for your distribution.

## Usage Example

```
BashHistoryMerger ~/.bash_history ~/old_bash_hist ~/old_bash_hist2 others... > ~/.bash_history.new
cat ~/.bash_history > ~/.bash_history.old
cat ~/.bash_history.new > ~/.bash_history
rm -f ~/.bash_history.new # and optionally ~/.bash_history.old ~/old_bash_hist ~/old_bash_hist2 others
```

## License
This program is licensed under the GNU General Public License, version 3. For more details, see: https://www.gnu.org/licenses/gpl-3.0.txt
