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
## Other considerations

For this program to function properly, it requires the following configuration:

```
HISTFILESIZE="100000000"
HISTSIZE="500000000"
HISTTIMEFORMAT="%a %b %Y %T %z "
```

Here's what each setting means:

- `HISTTIMEFORMAT`: Timestamps will be saved along with each command, formatted according to the specified pattern.
- `HISTFILESIZE`: Your history file size is set to accommodate 100 million lines, ensuring that command history is retained beyond the default limit.
- `HISTSIZE`: The maximum number of commands to remember in the current session is set to 500 million.

To implement these configurations, you can place them in a file under the `/etc/profile.d` directory. However, please ensure that you also modify `/etc/bashrc` to disable or adjust any conflicting current options related to command history.

Remember to restart your terminal session or run the appropriate source command to apply the changes before merging.

## License
This program is licensed under the GNU General Public License, version 3. For more details, see: https://www.gnu.org/licenses/gpl-3.0.txt
