#! /usr/bin/env ruby
require "numo/narray"

science = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70]
english = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

print "理科の合計"
p science.sum
print "英語の合計"
p english.sum
print "理科の平均"
p science.sum / science.length
print "英語の平均"
p english.sum / english.length
print "理科の標準偏差"
p Math.sqrt( science.sum / science.length ) 
print "英語の標準偏差"
p Math.sqrt(english.sum / english.length) 

print "理科の偏差値\n"  
for i in 0..science.length-1
	hensachi = 10 * (science[i] - science.sum / science.length) / Math.sqrt(science.sum / science.length)+ 50
	print i+1, ":", hensachi, "\n"
end

print "英語の偏差値\n"
for j in 0..english.length-1
	hensachi = 10 * (english[j] - english.sum / english.length) / Math.sqrt(english.sum / english.length) + 50
	print j+1, ":", hensachi, "\n"
end

print "理科の降順ソート"
p science.sort {|a, b| b <=> a}
print "英語の降順ソート"
p english.sort {|a, b| b <=> a}



    
