
/**
 * Rotate an array of n elements to the left by k steps.
 *
 * For example, with n = 7 and k = 3, the array {1,2,3,4,5,6,7} is rotated to {4,5,6,7,1,2,3}.
 */

void left_rotate(int* nums, int nums_size, int k) {
	int oidx, nidx, temp;
	int i, init_idx;

	k %= nums_size;
	if (k == 0) return;

	init_idx = 0;
	nidx = init_idx;
	temp = nums[nidx];
	for (i = 1; i <= nums_size; ++i) {
		oidx = nidx + k;
		if (oidx >= nums_size)
			oidx -= nums_size;

		if (oidx == init_idx) {
			nums[nidx] = temp;

			++init_idx;
			nidx = init_idx;
			temp = nums[nidx];
		} else {
			nums[nidx] = nums[oidx];
			nidx = oidx;
		}
	}
}
