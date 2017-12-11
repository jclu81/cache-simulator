# cacheSimulator
cs250p HW4
# Requirement
<span class="c8">Computer Systems Architecture</span>

<span class="c8">Homework 4</span>

<span class="c10">Cache Simulator</span><span class="c11">In this HW, you will build a simple simulator in either</span> <span class="c10">C or C++</span><span class="c11"> that reads a memory trace and simulates the action of a ‘</span><span class="c10">write-through with write-allocate</span><span class="c4">’ cache.</span>

<span class="c11">The replacement policy is</span> <span class="c10">LRU</span><span class="c4"> (Least Recently used) when all the blocks in the the set are valid.</span>

<span class="c4">The configuration of the cache is as follows:</span>

<span class="c10">Size</span><span class="c11">: 4096KB,</span> <span class="c10">Block Size</span><span class="c11">: 16B,</span> <span class="c10">Associativity</span><span class="c11">: Two-way,</span> <span class="c10">Address Size</span><span class="c4">: 32 Bits.</span>

<span class="c4"></span>

<span class="c4">This replacement works as follows in a two-way associative cache:</span>

<span class="c4">First way in a set is MRU and Second way is LRU. When the first block comes in it is stored in MRU position. When the next block comes, the old block is moved to LRU position and the new block is stored in MRU position. When the third blocks comes, block in LRU position is replaced by the block currently in MRU position and the new block occupies MRU position.  </span>

<span class="c4"></span>

<span class="c4">The valid bit for all the blocks is set to 0 initially. This bit changes to 1 when this block is occupied.</span>

<span class="c4">You don’t need a dirty bit, since it is not a write-back cache.</span>

<span class="c4"></span>

<span class="c4">Each trace is a series of lines, each listing a hexadecimal memory address followed by R or W to indicate a read or a write.</span>

<span class="c4">Example:</span>

<span class="c4">0041f7a0 R
13f5e2c0 R
31348900 W</span>

<span class="c4"></span>

<span class="c4">At the end of the simulation, i.e. all traces have been read and simulated, print out the following stats in following manner:</span>

<span class="c6">Total traces:</span>

<span class="c6">Reads:</span>

<span class="c6">Writes:</span>

<span class="c6">Cache hits:</span>

<span class="c6">Cache misses:</span>

<span class="c4"></span>

<span class="c10">Submission</span><span class="c4">:</span>

<span class="c4">Submit files with following naming convention:</span>

<span class="c1">Executable file:</span><span class="c4"> </span>

<span class="c10">memsim</span><span class="c4">. Make sure it works on openlab server. This executable has one command line argument i.e. the trace file. Therefore it must be able to run simply as:</span>

<span class="c11">$./memsim <input_trace_file_name></span>

<span class="c1">Source file(s):</span><span class="c4"> All together in a zip/tar/tar.gz file.</span>

<span class="c6">NOTE: Do NOT compress Executable and Source file(s) into zip, tar, etc. together.</span>

<span class="c6">Test Cases:</span>

1.  <span class="c1 c7">[https://drive.google.com/open?id=19dw3BDAYZex2eYaZyA3kvNVKFnJhAu7d](https://www.google.com/url?q=https://drive.google.com/open?id%3D19dw3BDAYZex2eYaZyA3kvNVKFnJhAu7d&sa=D&ust=1512961340459000&usg=AFQjCNEDpdlH4RaP7ObWGYSr5LzKhliu3w)</span>
2.  <span class="c1 c7">[https://drive.google.com/open?id=1pK3BoWTPsVKZ9oeXQDybBPwHkPkyA-DJ](https://www.google.com/url?q=https://drive.google.com/open?id%3D1pK3BoWTPsVKZ9oeXQDybBPwHkPkyA-DJ&sa=D&ust=1512961340460000&usg=AFQjCNGKY3-pjNFtdpbWgO9nJkDP2RNZXA)</span>
