<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0" 
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method='html' version='1.0' encoding='UTF-8' indent='yes' />

<xsl:template  match="/">
	<html>
	<body>	
		<table><p>
			<tr><td><xsl:value-of select="resume/address/name" /></td></tr>
			<tr><td><xsl:value-of select="resume/address/line1" /></td></tr>
			<tr><td><xsl:value-of select="resume/address/line2" /></td></tr>
			<tr><td><xsl:value-of select="resume/address/line3" /></td></tr>
		</p></table>
		<table border="0">
			<tr><td><b>Objective :</b></td>
				<td><xsl:value-of select="resume/objective_t" /></td>
			</tr>

			<tr>
				<td><b>Skills</b></td>
				<td>
					<xsl:for-each select="resume/assertions">
						<ul>
						<li><xsl:value-of select="m_skill" /></li>
						</ul>
					</xsl:for-each>
			</td></tr>
		</table>
		<table>
			
			<tr><td><b>Work History</b></td></tr>
			<xsl:for-each select="resume/evidence/work">
				<tr>
				<td><xsl:value-of select="employer" />
				<br /><xsl:value-of select="position" /></td>
				</tr>
			
				<tr>
				<td><ul>
				<xsl:for-each select="responsibility">
					<li><xsl:value-of select="m_task" /></li>
				</xsl:for-each>
				</ul></td>
				</tr>
			</xsl:for-each>
		</table>
		<table>
			<tr><td><b>Education</b></td></tr>
			<xsl:for-each select="resume/evidence/education">
				<tr><td><b><xsl:value-of select="school" /></b></td></tr>
				<tr><td><i><xsl:value-of select="status" /></i></td></tr>
				<br />
			</xsl:for-each>
		</table>
		
		<h4>Awards</h4>
		<ul>
		<i><li><xsl:value-of select="resume/evidence/award" /></li></i>
		</ul>
	</body>
	</html>
</xsl:template>
</xsl:stylesheet>	
